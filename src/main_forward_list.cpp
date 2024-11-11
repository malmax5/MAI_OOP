#include <iostream>

#include "../includes/forward_list/forward_list.hpp"
#include "../includes/allocators/map_memory_resource.hpp"

int main()
{
    ForwardList<int> list;
    list.PushFront(10);
    list.PushFront(20);
    list.PushFront(30);
    
    for (auto it = list.Begin(); it != list.End(); ++it) {
        std::cout << *it << " ";
    }
}