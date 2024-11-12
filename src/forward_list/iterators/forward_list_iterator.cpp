#include "../../../includes/forward_list/iterators/forward_list_iterator.hpp"

template<typename T>
ForwardIterator<T>::ForwardIterator(Node<T>* node) : current_(node) {}

template<typename T>
ForwardIterator<T>::ForwardIterator(const ForwardIterator& other) : current_(other.current_) {}

template<typename T>
ForwardIterator<T>& ForwardIterator<T>::operator=(const ForwardIterator& other) {
    if (this != &other) {
        current_ = other.current_;
    }
    return *this;
}

template<typename T>
Node<T>& ForwardIterator<T>::operator*() const {
    return *current_;
}

template<typename T>
Node<T>* ForwardIterator<T>::operator->() const {
    return current_;
}

template<typename T>
ForwardIterator<T>& ForwardIterator<T>::operator++() {
    if (current_) {
        current_ = current_->GetNext();
    }
    return *this;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator++(int) {
    ForwardIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
bool ForwardIterator<T>::operator==(const ForwardIterator& other) const {
    return current_ == other.current_;
}

template<typename T>
bool ForwardIterator<T>::operator!=(const ForwardIterator& other) const {
    return current_ != other.current_;
}

template<typename T>
void ForwardIterator<T>::SetIterator(Node<T>* node) {
    current_ = node;
}

template class ForwardIterator<int>;