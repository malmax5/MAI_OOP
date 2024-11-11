#pragma once

#include "/home/cbf/MAI/OOP/Lab_5/includes/forward_list/node.hpp"

template<typename T>
class ForwardIterator {
public:
    using ValueType = T;
    using Pointer = T*;
    using Reference = T&;

    ForwardIterator(Node<T>* node = nullptr) : current_(node) {}

    Reference operator*() const {
        return current_->GetData();
    }

    Pointer operator->() const {
        return current_;
    }

    ForwardIterator& operator++() {
        if (current_) {
            current_ = current_->GetNext();
        }
        return *this;
    }

    bool operator==(const ForwardIterator& other) const {
        return current_ == other.current_;
    }

    bool operator!=(const ForwardIterator& other) const {
        return current_ != other.current_;
    }

    void SetIterator(Node<T>* node) {
        current_ = node;
    }

private:
    Node<T>* current_;
};
