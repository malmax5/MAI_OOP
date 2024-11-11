#include <iostream>

#include "../includes/allocators/map_memory_resource.hpp"

int main()
{
    MapMemoryResource customResource;
    auto allocator = MapMemoryResource::InitAllocator<int>(customResource);

    int* ptr1 = allocator.allocate(10);
    int* ptr2 = allocator.allocate(20);

    allocator.deallocate(ptr1, 10);

    int* ptr3 = allocator.allocate(10);

    if (ptr3 == ptr1)
        std::cout << "Reused\n";
    else
        std::cout << "Reused fail\n";
    
    allocator.deallocate(ptr2, 20);
    allocator.deallocate(ptr3, 10);
}