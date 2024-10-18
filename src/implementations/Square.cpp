#include "Square.hpp"

template <typename TPoint>
Square<TPoint>::Square() : Rectangle<TPoint>() {}

template <typename TPoint>
Square<TPoint>::Square(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
    : Rectangle<TPoint>(topLeft, topRight, downRight, downLeft) {
    CheckOnRightFigure();
}

template <typename TPoint>
Square<TPoint>::Square(const Square& other) : Rectangle<TPoint>(other) {}

template <typename TPoint>
Square<TPoint>::Square(Square&& other) noexcept : Rectangle<TPoint>(std::move(other)) {}

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Square<TPoint>::Clone() const {
    return std::make_unique<Square>(*this);
}

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Square<TPoint>::Move() noexcept {
    return std::make_unique<Square>(std::move(*this));
}

template <typename TPoint>
void Square<TPoint>::CheckOnRightFigure() {
    TPoint diag1 = Point<TPoint>::Length(this->GetTopLeft(), this->GetDownRight());
    TPoint diag2 = Point<TPoint>::Length(this->GetTopRight(), this->GetDownLeft());
    TPoint eps = 1e-9;

    if (std::abs(diag1 - diag2) >= eps || std::abs(this->GetSize().first - this->GetSize().second) >= eps) {
        throw BadFigure("It's not a Square");
    }
}

template <typename TPoint>
Square<TPoint>& Square<TPoint>::operator=(const Square& other) {
    if (this != &other) {
        Rectangle<TPoint>::operator=(other);
    }
    return *this;
}

template <typename TPoint>
Square<TPoint>& Square<TPoint>::operator=(Square&& other) noexcept {
    if (this != &other) {
        Rectangle<TPoint>::operator=(std::move(other));
    }
    return *this;
}

template <typename TPoint>
Square<TPoint>::~Square() {}

template class Square<double>;