#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include "Rectangle.hpp"

template <typename TPoint>
class Square : virtual public Rectangle<TPoint> {
public:
    Square() : Rectangle<TPoint>() {}
    Square(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
        : Rectangle<TPoint>(topLeft, topRight, downRight, downLeft) {
        CheckOnRightFigure();
    }
    
    Square(const Square& other) : Rectangle<TPoint>(other) {}
    Square(Square&& other) noexcept : Rectangle<TPoint>(std::move(other)) {}

    // virtual Square* Clone() const override { return new Square(*this); }
    // virtual Square* Move() noexcept override { return new Square(std::move(*this)); }

    void CheckOnRightFigure() final {
        TPoint diag1 = Point<TPoint>::Length(this->GetTopLeft(), this->GetDownRight());
        TPoint diag2 = Point<TPoint>::Length(this->GetTopRight(), this->GetDownLeft());
        TPoint eps = 1e-9;

        if (std::abs(diag1 - diag2) < eps && std::abs(this->GetSize().first - this->GetSize().second) < eps) {
            throw BadFigure("It's not a Square");
        }
    }

    Square& operator= (const Square& other) {
        if (this != &other) {
            Rectangle<TPoint>::operator=(other);
        }
        return *this;
    }

    Square& operator= (Square&& other) noexcept {
        if (this != &other) {
            Rectangle<TPoint>::operator=(std::move(other));
        }
        return *this;
    }

    virtual ~Square() final {}
};

#endif