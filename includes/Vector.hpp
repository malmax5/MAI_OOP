#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"
#include <iostream>
#include <cmath>

template <typename T>
class Vector {
public:
    using ValueType = T;

    Vector() : xCord(0), yCord(0) {}
    Vector(ValueType xCord, ValueType yCord) : xCord(xCord), yCord(yCord) {}

    Vector(const Point<ValueType>& start, const Point<ValueType>& end) 
        : xCord(end.GetX() - start.GetX()), yCord(end.GetY() - start.GetY()) {}
    
    Vector(const Point<ValueType>& other) : xCord(other.GetX()), yCord(other.GetY()) {}
    // Vector(Point<ValueType>&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

    Vector(const Vector& other) : xCord(other.xCord), yCord(other.yCord) {}
    Vector(Vector&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

    ValueType GetX() const { return xCord; }
    ValueType GetY() const { return yCord; }

    static ValueType Length(const Vector& vec)
    {
        return std::sqrt((std::pow((vec.xCord), 2) + std::pow((vec.yCord), 2)));
    }

    static ValueType DotProduct(const Vector& vec1, const Vector& vec2) {
        return vec1.xCord * vec2.xCord + vec1.yCord * vec2.yCord;
    }

    static ValueType CrossProduct(const Vector& vec1, const Vector& vec2) {
        return vec1.xCord * vec2.yCord - vec1.yCord * vec2.xCord;
    }

    static Vector Perpendicular(const Vector& vec)
    {
        return Vector(vec.xCord, -vec.yCord);
    }

    static double Angle(const Vector& startVector, const Vector& Vector)
    {
        ValueType dx = Vector.xCord - startVector.xCord;
        ValueType dy = Vector.yCord - startVector.yCord;
        return std::atan2(dy, dx);
    }

    Vector& operator= (const Vector& other)
    {
        xCord = other.xCord;
        yCord = other.yCord;

        return *this;
    }

    Vector& operator= (Vector&& other) noexcept
    {
        xCord = std::move(other.xCord);
        yCord = std::move(other.yCord);

        return *this;
    }

    bool operator==(const Vector& other) const
    {
        return (xCord == other.xCord) && (yCord == other.yCord);
    }

    friend void swap(Vector& a, Vector& b) {
        using std::swap;
        swap(a.xCord, b.xCord);
        swap(a.yCord, b.yCord);
    }

public:
    template <typename TVector>
    friend std::istream& operator>>(std::istream& is, Vector<TVector>& Vector);

    template <typename TVector>
    friend std::ostream& operator<<(std::ostream& os, const Vector<TVector>& Vector);

private:
    ValueType xCord;
    ValueType yCord;
};

template <typename TVector>
std::istream& operator>>(std::istream& is, Vector<TVector>& vec)
{
    is >> vec.xCord >> vec.yCord;
    return is;
}

template <typename TVector>
std::ostream& operator<<(std::ostream& os, const Vector<TVector>& vec)
{
    os << "(" << vec.xCord << ", " << vec.yCord << ")";
    return os;
}

template <typename TPoint>
Vector<TPoint> operator-(const Point<TPoint>& start, const Point<TPoint>& end)
{
    return Vector<TPoint>(end.GetX() - start.GetX(), end.GetY() - start.GetY());
}

#endif