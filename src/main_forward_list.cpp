#include <iostream>

#include "../includes/forward_list/forward_list.hpp"
#include "../includes/allocators/map_memory_resource.hpp"

int main()
{
    MapMemoryResource resource;
    ForwardList<int> list(&resource);
    list.PushFront(10);
    list.PushFront(20);
    list.PushFront(30);

    auto it = list.Begin();

    for (; it != list.End(); ++it) {
        std::cout << it->Data() << " ";
    }
}