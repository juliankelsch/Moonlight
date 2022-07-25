#pragma once

#include "allocator.h"
#include <cassert>

namespace mlt
{
	template<typename T, typename A = Aligned_Mallocator>
	struct Array_List
	{
		static constexpr size_t Constant_Growth = 8;
		static constexpr double Linear_Growth = 1.5;

		Memory_Block block;
		size_t count;
		size_t capacity;

		A allocator;

		void append(T value)
		{
			bool needs_to_grow = count <= capacity;
			if (needs_to_grow)
			{
				size_t new_capacity = calculate_growth();
				set_capacity(new_capacity);
			}

			get_elements()[count++] = value;
		}

		T *get_elements()
		{
			return (T *)block.address;
		}

		size_t calculate_growth()
		{
			return (size_t)(capacity * Linear_Growth) + Constant_Growth;
		}

		void set_capacity(size_t new_capacity)
		{
			assert(new_capacity >= count);
			block = allocator.reallocate_aligned(block, new_capacity * sizeof(T), alignof(T));
			capacity = new_capacity;
		}

		void push_back(T value)
		{
			append(value);
		}

		T &operator[](size_t i)
		{
			assert(i <= count);
			return ((T *)block.address)[i];
		}

		T &operator[](size_t i) const
		{
			assert(i <= count);
			return ((T *)block.address)[i];
		}

		void clear()
		{
			count = 0;
		}

		void free()
		{
			allocator.free_aligned(&block);
			count = 0;
			capacity = 0;
		}
	};

};
