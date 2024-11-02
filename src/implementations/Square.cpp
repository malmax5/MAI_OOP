#include "../../includes/figures/Square.hpp"

#include "../../includes/concepts/ArithmeticConcept.hpp"

template <Arithmetic TPoint>
Square<TPoint>::Square() : Rectangle<TPoint>() {}

template <Arithmetic TPoint>
Square<TPoint>::Square(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
    : Rectangle<TPoint>(topLeft, topRight, downRight, downLeft) {
    CheckOnRightFigure();
}

template <Arithmetic TPoint>
Square<TPoint>::Square(const Square& other) : Rectangle<TPoint>(other) {}

template <Arithmetic TPoint>
Square<TPoint>::Square(Square&& other) noexcept : Rectangle<TPoint>(std::move(other)) {}

template <Arithmetic TPoint>
std::unique_ptr<Figure<TPoint>> Square<TPoint>::Clone() const {
    return std::make_unique<Square>(*this);
}

template <Arithmetic TPoint>
std::unique_ptr<Figure<TPoint>> Square<TPoint>::Move() noexcept {
    return std::make_unique<Square>(std::move(*this));
}

template <Arithmetic TPoint>
void Square<TPoint>::CheckOnRightFigure() {
    double diag1 = Point<TPoint>::Length(this->GetTopLeft(), this->GetDownRight());
    double diag2 = Point<TPoint>::Length(this->GetTopRight(), this->GetDownLeft());

    double eps = 1e-9;

    bool isEqualDiag = (std::abs(diag1 - diag2) <= eps);
    bool isEqualSize = false;

    if constexpr (std::is_signed<TPoint>::value)
        isEqualSize = std::abs(this->GetSize().first - this->GetSize().second) <= eps;
    else
        isEqualSize = (this->GetSize().first == this->GetSize().second);

    if (!isEqualDiag || !isEqualSize) {
        throw BadFigure("It's not a Square");
    }
}

template <Arithmetic TPoint>
Square<TPoint>& Square<TPoint>::operator=(const Square& other) {
    if (this != &other) {
        Rectangle<TPoint>::operator=(other);
    }
    return *this;
}

template <Arithmetic TPoint>
Square<TPoint>& Square<TPoint>::operator=(Square&& other) noexcept {
    if (this != &other) {
        Rectangle<TPoint>::operator=(std::move(other));
    }
    return *this;
}

template <Arithmetic TPoint>
Square<TPoint>::~Square() {}

template class Square<int>;
template class Square<double>;
