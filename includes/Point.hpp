#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Point {
public:
    using ValueType = T;

    Point();
    Point(ValueType xCord, ValueType yCord);
    Point(const Point& other);
    Point(Point&& other) noexcept;

    ValueType GetX() const;
    ValueType GetY() const;

    Point& operator= (const Point& other);
    Point& operator= (Point&& other) noexcept;

    bool operator==(const Point& other) const;
    static double Length(const Point& point1, const Point& point2);

    Point operator/(ValueType scalar) const;
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;

    bool operator>(const Point& other) const;
    bool operator<(const Point& other) const;

    template <typename TPoint>
    friend void swap(Point<TPoint>& a, Point<TPoint>& b);

    template <typename TPoint>
    friend std::istream& operator>>(std::istream& is, Point<TPoint>& point);

    template <typename TPoint>
    friend std::ostream& operator<<(std::ostream& os, const Point<TPoint>& point);

private:
    ValueType xCord;
    ValueType yCord;
};

#endif
