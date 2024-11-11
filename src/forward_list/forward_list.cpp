#include <iostream>
#include <memory_resource>

#include "../../includes/forward_list/forward_list.hpp"

template<typename T, typename Allocator>
ForwardList<T, Allocator>::ForwardList(std::pmr::memory_resource* mem_resource)
    : head_(nullptr), allocator_(mem_resource) {}

template<typename T,  typename Allocator>
ForwardList<T, Allocator>::ForwardList(const T& data, std::pmr::memory_resource* mem_resource)
    : head_(nullptr), allocator_(mem_resource) 
{
    PushFront(data);
}

template<typename T, typename Allocator>
ForwardList<T, Allocator>::~ForwardList()
{
    Clear();
}

template<typename T, typename Allocator>
void ForwardList<T, Allocator>::PushFront(const T& data)
{
    Node<T>* newNode = allocator_.allocate(1);
    allocator_.construct(newNode, data);
    newNode->SetNext(head_);
    head_ = newNode;
}

template<typename T, typename Allocator>
void ForwardList<T, Allocator>::PopFront()
{
    if (!head_)
    {
        return;
    }
    Node<T>* tmp = head_;
    head_ = head_->GetNext();
    allocator_.destroy(tmp);
    allocator_.deallocate(tmp, 1);
    tmp = nullptr;
}

template<typename T, typename Allocator>
void ForwardList<T, Allocator>::Clear()
{
    while (head_)
    {
        PopFront();
    }
}

template<typename T, typename Allocator>
T ForwardList<T, Allocator>::GetFront()
{
    return head_->GetData();
}


template class ForwardList<int>;
