#ifndef IFOUR_H
#define IFOUR_H

#include "C:\Users\CrazyBlackFire\Documents\Code\oop\Lab2\includes\implementations\Vector.h"

template<class T, class TT>
class IFour {
public:
    virtual void setNumber(const Vector<TT>& digits) = 0;
    virtual Vector<TT> getNumber() const = 0;
    virtual Vector<TT> add(const T& other) const = 0;
    virtual Vector<TT> subtract(const T& other) const = 0;

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