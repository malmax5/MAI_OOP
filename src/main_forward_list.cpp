#include <iostream>

#include "../includes/forward_list/forward_list.hpp"
#include "../includes/allocators/map_memory_resource.hpp"

int main()
{
    MapMemoryResource memory_resource;
    ForwardList<int> list(&memory_resource);
    list.PushFront(5);
    // list.PopFront();
    list.PushFront(6);
    // list.PushFront(7);
    std::cout << list.GetFront() << "\n";

    // list.Clear();
}