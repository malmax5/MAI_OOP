#pragma once

#include <iostream>
#include <memory_resource>

#include "node.hpp"

template<typename T, typename Allocator = std::pmr::polymorphic_allocator<Node<T>>>
class ForwardList
{
    using ValueType = T;

public:
    ForwardList(std::pmr::memory_resource* mem_resource = std::pmr::get_default_resource());
    ForwardList(const ValueType& data, std::pmr::memory_resource* mem_resource = std::pmr::get_default_resource());

    ~ForwardList();

    void PushFront(const ValueType& data);
    void PopFront();

    ValueType GetFront();

    void Clear();

private:
    Node<ValueType>* head_;
    Allocator allocator_;
};