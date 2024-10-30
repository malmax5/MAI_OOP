#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Point.hpp"
#include <iostream>
#include <memory>

template <typename TPoint>
class Figure
{
public:
    virtual ~Figure() = default;

    virtual Point<TPoint> CalculateCentroid() const = 0;
    virtual double CalculateArea() const = 0;

    virtual Point<TPoint> GetTopLeft() const = 0;
    virtual Point<TPoint> GetTopRight() const = 0;
    virtual Point<TPoint> GetDownRight() const = 0;
    virtual Point<TPoint> GetDownLeft() const = 0;

    virtual std::unique_ptr<Figure> Clone() const = 0;
    virtual std::unique_ptr<Figure> Move() noexcept = 0;
    
    virtual operator double() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure<TPoint>& figure) {
        os << figure.GetTopLeft() << " " << figure.GetTopRight() << " " << figure.GetDownRight() << " " << figure.GetDownLeft();
        return os;
    }
};

#endif