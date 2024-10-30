#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../includes/Figure.hpp"
#include "../includes/exceptions/BadFigure.hpp"
#include <vector>
#include <algorithm>

template <typename TPoint>
class Rectangle : virtual public Figure<TPoint> {
public:
    Rectangle();
    Rectangle(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Point<TPoint> GetTopLeft() const;
    Point<TPoint> GetTopRight() const;
    Point<TPoint> GetDownRight() const;
    Point<TPoint> GetDownLeft() const;
    std::pair<TPoint, TPoint> GetSize() const;

    virtual std::unique_ptr<Figure<TPoint>> Clone() const override;
    virtual std::unique_ptr<Figure<TPoint>> Move() noexcept override;

    virtual void ChangeArrangementIfBad();
    virtual void CheckOnRightFigure();
    virtual void SetSize();
    virtual Point<TPoint> CalculateCentroid() const override;
    virtual double CalculateArea() const override;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;
    
    virtual operator double() const override;
    virtual ~Rectangle() override;

public:
    template <typename TStreamPoint>
    friend std::istream& operator>>(std::istream& is, Rectangle<TStreamPoint>& rect);

    template <typename TStreamPoint>
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<TStreamPoint>& rect);

private:
    Point<TPoint> topLeft_;
    Point<TPoint> topRight_;
    Point<TPoint> downRight_;
    Point<TPoint> downLeft_;
    std::pair<TPoint, TPoint> size_;
};

#endif
