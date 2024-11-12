#pragma once

#include <iterator>
#include "../node.hpp"

template<typename T>
class ForwardIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    ForwardIterator(pointer node = nullptr);
    ForwardIterator(const ForwardIterator& other);
    ~ForwardIterator() = default;

    ForwardIterator& operator=(const ForwardIterator& other);

    reference operator*() const;
    pointer operator->() const;

    ForwardIterator& operator++();
    ForwardIterator operator++(int);

    bool operator==(const ForwardIterator& other) const;
    bool operator!=(const ForwardIterator& other) const;

    void SetIterator(Node<T>* node);

private:
    pointer current_;
};
