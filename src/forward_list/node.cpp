#include <iostream>
#include "../../includes/forward_list/node.hpp"

template<typename T>
Node<T>::Node() : data_()
{
    next_ = nullptr;
}

template<typename T>
Node<T>::Node(const ValueType& data) : data_(data)
{
    next_ = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other) : data_(other.data_)
{
    next_ = other.next_;
}

template<typename T>
Node<T>::Node(Node<T>&& other) noexcept : data_(std::move(other.data_))
{
    next_ = std::move(other.next_);
}

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

template <typename T>
bool Node<T>::operator==(const Node& other) const
{
    return data_ == other.data_;
}

template<typename T>
Node<T>::~Node()
{
    next_ = nullptr;
}

template<typename T>
typename Node<T>::ValueType Node<T>::Data()
{
    return data_;
}

template<typename T>
const typename Node<T>::ValueType Node<T>::Data() const
{
    return data_;
}

template<typename T>
void Node<T>::SetNext(Node<ValueType>* next)
{
    next_ = next;
}

template<typename T>
Node<typename Node<T>::ValueType>* Node<T>::GetNext()
{
    return reinterpret_cast<Node<T>*>(next_);
}

template<typename T>
typename Node<T>::ValueType& Node<T>::GetData()
{
    return data_;
}

template<typename T>
const typename Node<T>::ValueType& Node<T>::GetData() const
{
    return data_;
}

template<typename T>
void Node<T>::SetData(ValueType value)
{
    data_ = value;
}

template class Node<int>;
