#pragma once

#include <iostream>
#include <map>
#include <memory_resource>
#include <cstdlib>
#include <cstddef>

#include "extensions/map_memory_resource_adds.hpp"

class MapMemoryResource : public std::pmr::memory_resource, public MapMemoryResourceAddition<MapMemoryResource>
{
public:
    MapMemoryResource() = default;
    ~MapMemoryResource()
    {
        for (const auto& [ptr, size] : allocated_blocks)
        {
            std::free(ptr);
        }
        for (const auto& [ptr, size] : deallocated_blocks)
        {
            std::free(ptr);
        }
    }

protected:
    virtual void* do_allocate(size_t bytes, size_t alignment) override
    {
        for (auto it = deallocated_blocks.begin(); it != deallocated_blocks.end(); it++)
        {
            if (it->second >= bytes)
            {
                void* ptr = it->first;
                deallocated_blocks.erase(it);
                allocated_blocks[ptr] = bytes;
                return ptr;
            }
        }

        void* ptr = aligned_alloc(alignment, bytes);
        if (!ptr)
        {
            throw std::bad_alloc();
        }
        allocated_blocks[ptr] = bytes;
        return ptr;
    }

    virtual void do_deallocate(void* ptr, size_t, size_t) override
    {
        auto it = allocated_blocks.find(ptr);
        if (it != allocated_blocks.end())
        {
            deallocated_blocks[ptr] = it->second;
            allocated_blocks.erase(ptr);
        }
    }

    virtual bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override
    {
        return this == &other;
    }

private:
    std::map<void*, size_t> allocated_blocks;
    std::map<void*, size_t> deallocated_blocks;
};
