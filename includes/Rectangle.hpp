#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../includes/Figure.hpp"
#include "../includes/Point.hpp"
#include "../includes/exceptions/BadFigure.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cmath>

template <typename TPoint>
class Rectangle : virtual public Figure<TPoint> {
public:
    Rectangle() : topLeft_(0, 0), topRight_(0, 0), downRight_(0, 0), downLeft_(0, 0) {}
    Rectangle(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
        : topLeft_(topLeft), topRight_(topRight), downRight_(downRight), downLeft_(downLeft) {
        ChangeArrangementIfBad();
        CheckOnRightFigure();
        SetSize();
    }
    Rectangle(const Rectangle& other)
        : topLeft_(other.topLeft_), topRight_(other.topRight_), downRight_(other.downRight_), downLeft_(other.downLeft_), size_(other.size_) {}
    Rectangle(Rectangle&& other) noexcept
        : topLeft_(std::move(other.topLeft_)),
          topRight_(std::move(other.topRight_)),
          downRight_(std::move(other.downRight_)),
          downLeft_(std::move(other.downLeft_)),
          size_(std::move(other.size_)) {}

    Point<TPoint> GetTopLeft() const { return topLeft_; }
    Point<TPoint> GetTopRight() const { return topRight_; }
    Point<TPoint> GetDownRight() const { return downRight_; }
    Point<TPoint> GetDownLeft() const { return downLeft_; }
    std::pair<TPoint, TPoint> GetSize() const { return size_; }

    // virtual Rectangle* Clone() const override { return new Rectangle(*this); }
    // virtual Rectangle* Move() noexcept override { return new Rectangle(std::move(*this)); }

    virtual void ChangeArrangementIfBad() {
        std::vector<Point<TPoint>> goodArrangement {topLeft_, topRight_, downRight_, downLeft_};
        std::sort(goodArrangement.begin(), goodArrangement.end());
        topLeft_ = std::move(goodArrangement[2]);
        topRight_ = std::move(goodArrangement[3]);
        downRight_ = std::move(goodArrangement[1]);
        downLeft_ = std::move(goodArrangement[0]);
    }

    virtual void CheckOnRightFigure() {
        TPoint eps = 1e-9;

        TPoint diag1 = Point<TPoint>::Length(topLeft_, downRight_);
        TPoint diag2 = Point<TPoint>::Length(topRight_, downLeft_);
        if (std::abs(diag1 - diag2) < eps) {
            throw BadFigure("It's not a Rectangle");
        }
    }

    virtual void SetSize() {
        TPoint firstSide = Point<TPoint>::Length(topLeft_, topRight_);
        TPoint secondSide = Point<TPoint>::Length(topLeft_, downLeft_);
        size_ = {firstSide, secondSide};
    }

    virtual Point<TPoint> CalculateCentroid() const override {
        TPoint xCord = (topLeft_.GetX() + topRight_.GetX()) / 2;
        TPoint yCord = (topLeft_.GetY() + downLeft_.GetY()) / 2;
        Point<TPoint> centroid(xCord, yCord);
        return centroid;
    }

    virtual double CalculateArea() const override {
        return size_.first * size_.second;
    }

    Rectangle& operator= (const Rectangle& other) {
        if (this != &other) {
            topLeft_ = other.topLeft_;
            topRight_ = other.topRight_;
            downRight_ = other.downRight_;
            downLeft_ = other.downLeft_;
            size_ = other.size_;
        }
        return *this;
    }

    Rectangle& operator= (Rectangle&& other) noexcept {
        if (this != &other) {
            topLeft_ = std::move(other.topLeft_);
            topRight_ = std::move(other.topRight_);
            downRight_ = std::move(other.downRight_);
            downLeft_ = std::move(other.downLeft_);
            size_ = std::move(other.size_);
        }
        return *this;
    }

    bool operator==(const Rectangle& other) const {
        return topLeft_ == other.topLeft_ &&
               topRight_ == other.topRight_ &&
               downRight_ == other.downRight_ &&
               downLeft_ == other.downLeft_;
    }

    virtual operator double() const override {
        return CalculateArea();
    }

    virtual ~Rectangle() override {}

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

template <typename TStreamPoint>
std::istream& operator>>(std::istream& is, Rectangle<TStreamPoint>& rect) {
    is >> rect.topLeft_ >> rect.topRight_ >> rect.downRight_ >> rect.downLeft_;
    rect.ChangeArrangementIfBad();
    rect.CheckOnRightFigure();
    rect.SetSize();
    return is;
}

template <typename TStreamPoint>
std::ostream& operator<<(std::ostream& os, const Rectangle<TStreamPoint>& rect) {
    os << rect.topLeft_ << " " << rect.topRight_ << " " << rect.downRight_ << " " << rect.downLeft_;
    return os;
}

#endif