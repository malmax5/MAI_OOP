#pragma once

#include <iostream>

template<class T>
struct BaseNode
{
    using ValueType = T;

protected:
    BaseNode* next_;
};

template<class T>
struct Node : private BaseNode<T>
{
    using typename BaseNode<T>::ValueType;
    using BaseNode<T>::next_;

    template<typename U, typename Allocator>
    friend class ForwardList;

    template<typename U>
    friend class ForwardIterator;

public:
    Node();
    Node(const ValueType& data);
    Node(const Node& other);
    Node(Node&& other) noexcept;

    Node& operator=(const Node& other);
    Node& operator=(Node&& other) noexcept;
    bool operator==(const Node& other) const;

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
    // Node* next_;
    ValueType data_;
};
