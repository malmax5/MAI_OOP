#ifndef IFOUR_H
#define IFOUR_H

#include <vector>

template<class T, class TT>
class IFour {
public:
    virtual void setNumber(const std::vector<TT>& digits) = 0;
    virtual std::vector<TT> getNumber() const = 0;
    virtual std::vector<TT> add(const T& other) const = 0;
    virtual std::vector<TT> subtract(const T& other) const = 0;

    virtual T operator+(const T& other) const = 0;
    virtual T operator-(const T& other) const = 0;
    virtual T& operator=(const T& other) = 0;
    virtual T& operator=(T&& other) noexcept = 0;

    virtual bool operator>(const T& other) const = 0;
    virtual bool operator<(const T& other) const = 0;
    virtual bool operator==(const T& other) const = 0;

    virtual T& operator+=(const T& other) = 0;
    virtual T& operator-=(const T& other) = 0;
};

#endif