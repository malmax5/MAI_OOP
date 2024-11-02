#ifndef FIGURECONCEPT_HPP
#define FIGURECONCEPT_HPP

#include<iostream>
#include<concepts>

#include "../coordinates/Point.hpp"

template<typename T>
concept GeometricShape = requires (T a)
{
    { a.CalculateCentroid() } -> std::same_as<Point<double>>;
    { a.CalculateArea() } -> std::same_as<double>;
};

#endif