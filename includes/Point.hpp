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
        return (xCord == other.xCord) && (yCord == other.yCord);
    }

    static ValueType Length(const Point& point1, const Point& point2)
    {
        return std::sqrt((std::pow((point1.xCord - point2.xCord), 2) + std::pow((point1.yCord - point2.yCord), 2)));
    }

    static double Angle(const Point& startPoint, const Point& point)
    {
        ValueType dx = point.xCord - startPoint.xCord;
        ValueType dy = point.yCord - startPoint.yCord;
        return std::atan2(dy, dx);
    }

    bool operator>(const Point<ValueType>& other)
    {
        return xCord > other.xCord || yCord > other.yCord;
    }

    bool operator<(const Point<ValueType>& other)
    {
        return xCord < other.xCord || yCord < other.yCord;
    }

public:
    template <typename TPoint>
    friend std::istream& operator>>(std::istream& is, Point<TPoint>& point);

    template <typename TPoint>
    friend std::ostream& operator<<(std::ostream& os, const Point<TPoint>& point);

public:
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