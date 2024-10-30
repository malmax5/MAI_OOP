#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Rectangle.hpp"

template <typename TPoint>
class Square : virtual public Rectangle<TPoint> {
public:
    Square();
    Square(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft);
    
    Square(const Square& other);
    Square(Square&& other) noexcept;

    virtual std::unique_ptr<Figure<TPoint>> Clone() const override;
    virtual std::unique_ptr<Figure<TPoint>> Move() noexcept override;

    void CheckOnRightFigure() final;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;

    virtual ~Square() final;
};

#endif
