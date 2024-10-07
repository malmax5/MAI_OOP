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

    void CheckOnRightFigure() final {
        TPoint diag1 = Point<TPoint>::Length(this->GetTopLeft(), this->GetDownRight());
        TPoint diag2 = Point<TPoint>::Length(this->GetTopRight(), this->GetDownLeft());

        if (!(diag1 == diag2 && this->GetSize().first == this->GetSize().second)) {
            throw BadFigure("It's not a Square");
        }
    }

    virtual ~Square() final {}
};

#endif