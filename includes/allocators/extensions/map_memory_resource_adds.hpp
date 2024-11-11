#pragma once

#include <iostream>
#include <memory_resource>

template<class TAlloc>
class MapMemoryResourceAddition
{
public:
    template<typename TValue>
    static std::pmr::polymorphic_allocator<TValue> InitAllocator(TAlloc& customResource)
    {
        return std::pmr::polymorphic_allocator<TValue>(&customResource);
    }
};