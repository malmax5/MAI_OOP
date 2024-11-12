#pragma once

#include <iostream>

template<typename T>
class Node
{
    using ValueType = T;

public:
    Node();
    Node(const ValueType& data);
    Node(const Node& other);
    Node(Node&& other) noexcept;

    Node& operator=(const Node& other);
    Node& operator=(Node&& other) noexcept;

    ~Node();

    ValueType Data();
    const ValueType Data() const;

protected:
    ValueType& GetData();
    const ValueType& GetData() const;
    void SetData(ValueType value);

    void SetNext(Node<ValueType>* next);
    Node<ValueType>* GetNext();

private:
    Node* next_;
    ValueType data_;

    template<typename U, typename Allocator>
    friend class ForwardList;

    template<typename U>
    friend class ForwardIterator;
};

