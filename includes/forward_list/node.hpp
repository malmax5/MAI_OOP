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

    ValueType GetData();

public:
    void SetNext(Node<ValueType>* next);
    Node<ValueType>* GetNext();

private:
    Node* next_;
    ValueType data_;

};