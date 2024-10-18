#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "../includes/Figure.hpp"
#include "../includes/Vector.hpp"
#include "../includes/exceptions/BadFigure.hpp"
#include <vector>
#include <algorithm>

template <typename TPoint>
class Trapezoid : virtual public Figure<TPoint> {
public:
    Trapezoid();
    Trapezoid(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft);
    
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;

    Point<TPoint> GetTopLeft() const;
    Point<TPoint> GetTopRight() const;
    Point<TPoint> GetDownRight() const;
    Point<TPoint> GetDownLeft() const;

    virtual std::unique_ptr<Figure<TPoint>> Clone() const override;
    virtual std::unique_ptr<Figure<TPoint>> Move() noexcept override;

    void ChangeArrangementIfBad();
    virtual void CheckOnRightFigure();
    virtual void SetSize();
    TPoint CalculateHeight() const;
    Point<TPoint> CalculateCentroid() const;
    virtual double CalculateArea() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Trapezoid& other) const;
    virtual operator double() const override;
    virtual ~Trapezoid() override;

public:
    template <typename TStreamPoint>
    friend std::istream& operator>>(std::istream& is, Trapezoid<TStreamPoint>& trap);

    template <typename TStreamPoint>
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid<TStreamPoint>& trap);

private:
    Point<TPoint> topLeft_;
    Point<TPoint> topRight_;
    Point<TPoint> downRight_;
    Point<TPoint> downLeft_;
    std::vector<TPoint> size_;
};

#endif
