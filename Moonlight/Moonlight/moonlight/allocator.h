#pragma once

#include <malloc.h>
#include <stdint.h>

// Notes:
// - reallocate_aligned() assumes alignment is the same as when first allocated

namespace mlt
{
	struct Memory_Block
	{
		union
		{
			void *address;
			uint8_t *as_u8;
		};
		size_t size;
	};


	struct Aligned_Mallocator
	{
		Memory_Block allocate_aligned(size_t size, size_t alignment)
		{
			return { _aligned_malloc(size, alignment), size };
		}

		Memory_Block reallocate_aligned(Memory_Block block, size_t size, size_t alignment)
		{
			return { _aligned_realloc(block.address, size, alignment), size };
		}

		void free_aligned(Memory_Block *block)
		{
			_aligned_free(block->address);
			block->address = nullptr;
			block->size = 0;
		}
	};

	struct Arena_Allocator
	{
		Memory_Block memory;
		size_t used;

		bool owns(Memory_Block block)
		{
			return (block.as_u8 >= memory.as_u8) 
				&& (block.as_u8 + block.size < memory.as_u8 + used);
		}

		Memory_Block allocate_aligned(size_t size, size_t alignment)
		{

		}

		Memory_Block reallocate_aligned(Memory_Block block, size_t size, size_t alignment)
		{
			assert(owns(block) && "Arena allocator received a block it doesn't own.");

			bool is_first_allocation = memory.size == 0 && memory.address != nullptr;
			if (is_first_allocation)
			{
				return allocate_aligned(size, alignment);
			}

			bool is_most_recent_allocation = memory.as_u8 + used == block.as_u8 + block.size;
			if (is_most_recent_allocation)
			{
				used -= block.size;
				return allocate_aligned(size, alignment);
			}

			assert(false && "Arena allocator can only reallocate if it is the first allocation or if the block is the most recently allocated one.");

			return { nullptr, 0 };
		}


		void free_aligned(Memory_Block *block)
		{
			assert(owns(*block) && "Arena allocator received a block it doesn't own.");

			if (memory.as_u8 + used == block->as_u8 + block->size)
			{
				used -= block->size;
				block->size = 0;
				block->address = nullptr;
			}

			assert(false && "Free can only be called on arena allocators if the block to be free'd is the most recently allocated block.");
		}
	};

	/*
	template <typename Primary, typename Fallback>
	class Fallback_Allocator : private Primary, private Fallback
	{
		Memory_Block allocate_aligned(size_t size, size_t alignment);
		free_aligned(Memory_Block *block);
	};
	*/
};

