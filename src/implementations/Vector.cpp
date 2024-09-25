#include "C:\Users\CrazyBlackFire\Documents\Code\oop\Lab2\includes\implementations\Vector.h"
#include <memory>
#include <cstdlib>

const int TEN = 10;

template <typename T>
Vector<T>::Vector(const T& value) : size_(1), capacity_(1)
{
    size_t count = 1;
    arr_ = reinterpret_cast<T*>(new int8_t[count* sizeof(T)]);
    new (arr_) T(value);
}

template <typename T>
Vector<T>::Vector() : arr_(nullptr), size_(0), capacity_(0)
{
}

template <typename T>
Vector<T>::Vector(size_t count, const T& value) : size_(count), capacity_(count)
{
    count = (count > TEN) ? count : TEN;
    arr_ = reinterpret_cast<T*>(new int8_t[count * sizeof(T)]);
    for (size_t i = 0; i < count; ++i)
    {
        new (arr_ + i) T(value);
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    size_ = other.size_;
    capacity_ = (size_ > TEN) ? size_ : TEN;
    arr_ = reinterpret_cast<T*>(new int8_t[capacity_ * sizeof(T)]);
    std::uninitialized_copy(other.arr_, other.arr_ + size_, arr_);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this == &other)
    {
        return *this;
    }
    Clear();
    Reserve(other.capacity_);
    size_ = other.size_;
    capacity_ = other.capacity_;
    std::uninitialized_copy(other.arr_, other.arr_ + size_, arr_);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    if (this == &other)
    {
        return *this;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = other.arr_;
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = other.arr_;
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init)
{
    size_ = init.size();
    capacity_ = (init.size() > TEN) ? init.size() : TEN;
    arr_ = reinterpret_cast<T*>(new int8_t[capacity_ * sizeof(T)]);
    std::uninitialized_copy(init.begin(), init.end(), arr_);
}

template <typename T>
T& Vector<T>::operator[](size_t pos)
{
    return arr_[pos];
}

template <typename T>
T& Vector<T>::Front() const noexcept
{
    return arr_[0];
}

template <typename T>
bool Vector<T>::IsEmpty() const noexcept
{
    return size_ == 0;
}

template <typename T>
T& Vector<T>::Back() const noexcept
{
    return arr_[size_ - 1];
}

template <typename T>
T* Vector<T>::Data() const noexcept
{
    return arr_;
}

template <typename T>
size_t Vector<T>::Size() const noexcept
{
    return size_;
}

template <typename T>
size_t Vector<T>::Capacity() const noexcept
{
    return capacity_;
}

template <typename T>
void Vector<T>::Reserve(size_t new_cap)
{
    if (new_cap <= capacity_)
    {
        return;
    }
    T* new_arr = reinterpret_cast<T*>(new int8_t[new_cap * sizeof(T)]);
    for (size_t i = 0; i < size_; ++i)
    {
        new (new_arr + i) T(std::move(arr_[i]));
    }
    for (size_t i = 0; i < size_; ++i)
    {
        arr_[i].~T();
    }
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = new_cap;
}

template <typename T>
void Vector<T>::PushBack(const std::unique_ptr<T>&& value)
{
    if (capacity_ == 0)
    {
        Reserve(TEN);
    }
    if (size_ == capacity_)
    {
        Reserve(capacity_ * 2);
    }
    new (arr_ + size_) T(std::move(*value));
    size_++;
}

template <typename T>
void Vector<T>::PushBack(T value)
{
    if (capacity_ == 0)
    {
        Reserve(TEN);
    }
    if (size_ == capacity_)
    {
        Reserve(capacity_ * 2);
    }
    new (arr_ + size_) T(std::move(value));
    size_++;
}

template <typename T>
void Vector<T>::PopBack()
{
    arr_[size_ - 1].~T();
    size_--;
}

template <typename T>
void Vector<T>::Resize(size_t count, const T& value)
{
    if (count < size_)
    {
        for (size_t i = count; i < size_; ++i)
        {
            arr_[i].~T();
        }
        size_ = count;
    } else if (count > size_)
    {
        if (count > capacity_)
        {
            Reserve(count);
        }
        for (size_t i = size_; i < count; ++i)
        {
            new (arr_ + i) T(value);
        }
        size_ = count;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    for (size_t i = 0; i < size_; ++i)
    {
        arr_[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(arr_);
}

template <>
class Vector<void*>
{
public:
    Vector() : arr_(nullptr), size_(0), capacity_(0)
    {
    }

    Vector(size_t count, void* value) : size_(count), capacity_(count)
    {
        count = (count > TEN) ? count : TEN;
        arr_ = reinterpret_cast<void**>(new int8_t[count * sizeof(void*)]);
        for (size_t i = 0; i < count; ++i)
        {
            new (arr_ + i) void*(value);
        }
    }

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;
    Vector(Vector&&) = delete;
    Vector& operator=(Vector&&) = delete;

    Vector(std::initializer_list<void*> init)
    {
        size_ = init.size();
        capacity_ = (init.size() > TEN) ? init.size() : TEN;
        arr_ = reinterpret_cast<void**>(new int8_t[capacity_ * sizeof(void*)]);
        std::uninitialized_copy(init.begin(), init.end(), arr_);
    }

    void* operator[](size_t pos)
    {
        return arr_[pos];
    }

    const void* operator[](size_t pos) const
    {
        return arr_[pos];
    }

    void* Front() const noexcept
    {
        return arr_[0];
    }

    bool IsEmpty() const noexcept
    {
        return size_ == 0;
    }

    void* Back() const noexcept
    {
        return arr_[size_ - 1];
    }

    void** Data() const noexcept
    {
        return arr_;
    }

    size_t Size() const noexcept
    {
        return size_;
    }

    size_t Capacity() const noexcept
    {
        return capacity_;
    }

    void Reserve(size_t new_cap)
    {
        if (new_cap <= capacity_)
        {
            return;
        }
        void** new_arr = reinterpret_cast<void**>(new int8_t[new_cap * sizeof(void*)]);
        for (size_t i = 0; i < size_; ++i)
        {
            new (new_arr + i) void*(std::move(arr_[i]));
        }
        for (size_t i = 0; i < size_; ++i)
        {
            free(arr_[i]);
        }
        delete[] arr_;
        arr_ = new_arr;
        capacity_ = new_cap;
    }

    void PushBack(void* value)
    {
        if (capacity_ == 0)
        {
            Reserve(TEN);
        }
        if (size_ == capacity_)
        {
            Reserve(capacity_ * 2);
        }
        new (arr_ + size_) void*(value);
        size_++;
    }

    void PopBack()
    {
        free(arr_[size_ - 1]);
        size_--;
    }

    ~Vector()
    {
        for (size_t i = 0; i < size_; ++i)
        {
            free(arr_[i]);
        }
        delete[] reinterpret_cast<int8_t*>(arr_);
    }

private:
    void** arr_;
    size_t size_;
    size_t capacity_;
};

template <typename T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
{
    size_t minSize = std::min(lhs.Size(), rhs.Size());
    for (size_t i = 0; i < minSize; ++i)
    {
        if (lhs[i] > rhs[i])
        {
            return true;
        } else if (lhs[i] < rhs[i])
        {
            return false;
        }
    }
    return lhs.Size() > rhs.Size();
}

template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if (lhs.Size() != rhs.Size())
    {
        return false;
    }
    for (size_t i = 0; i < lhs.Size(); ++i)
    {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}