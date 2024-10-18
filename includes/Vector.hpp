#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"
#include <iostream>
#include <cmath>

template <typename T>
class Vector {
public:
    using ValueType = T;

    Vector();
    Vector(ValueType xCord, ValueType yCord);
    Vector(const Point<ValueType>& start, const Point<ValueType>& end);
    Vector(const Point<ValueType>& other);
    Vector(Point<ValueType>&& other) noexcept;

    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    ValueType GetX() const;
    ValueType GetY() const;

    static ValueType Length(const Vector& vec);
    static ValueType DotProduct(const Vector& vec1, const Vector& vec2);
    static ValueType CrossProduct(const Vector& vec1, const Vector& vec2);
    static Vector Perpendicular(const Vector& vec);
    static double Angle(const Vector& startVector, const Vector& endVector);

    Vector& operator= (const Vector& other);
    Vector& operator= (Vector&& other) noexcept;
    bool operator==(const Vector& other) const;

    template <typename TVector>
    friend std::istream& operator>>(std::istream& is, Vector<TVector>& vec);
    
    template <typename TVector>
    friend std::ostream& operator<<(std::ostream& os, const Vector<TVector>& vec);

private:
    ValueType xCord;
    ValueType yCord;
};

#endif
