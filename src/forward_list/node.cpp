#include <iostream>

#include "../../includes/forward_list/node.hpp"

template<typename T>
Node<T>::Node() : next_(nullptr), data_() {}

template<typename T>
Node<T>::Node(const ValueType& data) : next_(nullptr), data_(data) {}

template<typename T>
Node<T>::Node(const Node<T>& other) : next_(other.next_), data_(other.data_) {}

template<typename T>
Node<T>::Node(Node<T>&& other) noexcept : next_(std::move(other.next_)), data_(std::move(other.data_)) {}

template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    data_ = other.data_;
    next_ = other.next_;

    return *this;
}

template<typename T>
Node<T>& Node<T>::operator=(Node<T>&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    data_ = std::move(other.data_);
    next_ = std::move(other.next_);

    return *this;
}

template<typename T>
Node<T>::~Node()
{
    next_ = nullptr;
    std::free(this);
}

template<typename T>
void Node<T>::SetNext(Node<T>* next)
{
    next_ = next;
}

template<typename T>
Node<T>* Node<T>::GetNext()
{
    return next_;
}

template<typename T>
T Node<T>::GetData()
{
    return data_;
}


template class Node<int>;
