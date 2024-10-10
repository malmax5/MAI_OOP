#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Point {
public:
    using ValueType = T;

    Point() : xCord(0), yCord(0) {}
    Point(ValueType xCord, ValueType yCord) : xCord(xCord), yCord(yCord) {}

    Point(const Point& other) : xCord(other.xCord), yCord(other.yCord) {}
    Point(Point&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

    ValueType GetX() const { return xCord; }
    ValueType GetY() const { return yCord; }

    Point& operator= (const Point& other)
    {
        xCord = other.xCord;
        yCord = other.yCord;

        return *this;
    }

    Point& operator= (Point&& other) noexcept
    {
        xCord = std::move(other.xCord);
        yCord = std::move(other.yCord);

        return *this;
    }

    bool operator==(const Point& other) const
    {
         const ValueType epsilon = 1e-9;
        return std::abs(xCord - other.xCord) < epsilon && std::abs(yCord - other.yCord) < epsilon;
    }

    static ValueType Length(const Point& point1, const Point& point2)
    {
        return std::sqrt((std::pow((point1.xCord - point2.xCord), 2) + std::pow((point1.yCord - point2.yCord), 2)));
    }

    Point operator/(ValueType scalar) const
    {
        return Point(xCord / scalar, yCord / scalar);
    }

    // Point<ValueType> operator-(const Point<ValueType>& other) const
    // {
    //     return Point<ValueType>(this->xCord - other.xCord, this->yCord - other.yCord);
    // }

    Point<ValueType> operator+(const Point<ValueType>& other) const
    {
        return Point<ValueType>(this->xCord + other.xCord, this->yCord + other.yCord);
    }

    bool operator>(const Point<ValueType>& other)
    {
        return xCord > other.xCord || yCord > other.yCord;
    }

    bool operator<(const Point<ValueType>& other)
    {
        return xCord < other.xCord || yCord < other.yCord;
    }

    friend void swap(Point& a, Point& b) {
        using std::swap;
        swap(a.xCord, b.xCord);
        swap(a.yCord, b.yCord);
    }

public:
    template <typename TPoint>
    friend std::istream& operator>>(std::istream& is, Point<TPoint>& point);

    template <typename TPoint>
    friend std::ostream& operator<<(std::ostream& os, const Point<TPoint>& point);

private:
    ValueType xCord;
    ValueType yCord;
};

template <typename TPoint>
std::istream& operator>>(std::istream& is, Point<TPoint>& point)
{
    is >> point.xCord >> point.yCord;
    return is;
}

template <typename TPoint>
std::ostream& operator<<(std::ostream& os, const Point<TPoint>& point)
{
    os << "(" << point.xCord << ", " << point.yCord << ")";
    return os;
}

#endif