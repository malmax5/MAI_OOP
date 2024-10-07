#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "../includes/Figure.hpp"
#include "../includes/Point.hpp"
#include "../includes/exceptions/BadFigure.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cmath>

template <typename TPoint>
class Trapezoid : virtual public Figure<TPoint> {
public:
    Trapezoid() : topLeft_(0, 0), topRight_(0, 0), downRight_(0, 0), downLeft_(0, 0) {}
    Trapezoid(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
        : topLeft_(topLeft), topRight_(topRight), downRight_(downRight), downLeft_(downLeft)
    {
        ChangeArrangementIfBad();
        CheckOnRightFigure();
    }
    Trapezoid(const Trapezoid& other)
        : topLeft_(other.topLeft_), topRight_(other.topRight_), downRight_(other.downRight_), downLeft_(other.downLeft_)
    {}
    Trapezoid(Trapezoid&& other) noexcept
        : topLeft_(std::move(other.topLeft_)),
          topRight_(std::move(other.topRight_)),
          downRight_(std::move(other.downRight_)),
          downLeft_(std::move(other.downLeft_))
    {}

    static bool ComparePoints(const Point<TPoint>& startPoint, const Point<TPoint>& p1, const Point<TPoint>& p2) {
        TPoint angle1 = Point<TPoint>::Angle(startPoint, p1);
        TPoint angle2 = Point<TPoint>::Angle(startPoint, p2);
        return angle1 < angle2;
    }

    void ChangeArrangementIfBad() {
        std::vector<Point<TPoint>> goodArrangement {topLeft_, topRight_, downRight_, downLeft_};
        std::sort(goodArrangement.begin(), goodArrangement.end());
        Point<TPoint> startPoint = goodArrangement[0];
        std::sort(goodArrangement.begin(), goodArrangement.end(), 
                  [&startPoint](const Point<TPoint>& p1, const Point<TPoint>& p2) {
                      return ComparePoints(startPoint, p1, p2);
                  });

        if (Point<TPoint>::Length(goodArrangement[0], goodArrangement[1]) == Point<TPoint>::Length(goodArrangement[2], goodArrangement[3])) {
            downLeft_ = std::move(goodArrangement[0]);
            topLeft_ = std::move(goodArrangement[1]);
            topRight_ = std::move(goodArrangement[2]);
            downRight_ = std::move(goodArrangement[3]);
        } else {
            downLeft_ = std::move(goodArrangement[1]);
            topLeft_ = std::move(goodArrangement[2]);
            topRight_ = std::move(goodArrangement[3]);
            downRight_ = std::move(goodArrangement[0]);
        }
    }

    virtual void CheckOnRightFigure() {
        TPoint diag1 = Point<TPoint>::Length(topLeft_, downRight_);
        TPoint diag2 = Point<TPoint>::Length(topRight_, downLeft_);
        TPoint side1 = Point<TPoint>::Length(downLeft_, topLeft_);
        TPoint side2 = Point<TPoint>::Length(topLeft_, topRight_);
        TPoint side3 = Point<TPoint>::Length(topRight_, downRight_);
        TPoint side4 = Point<TPoint>::Length(downRight_, downLeft_);
        if (!(diag1 == diag2 && (side1 == side3 && side2 != side4 || side1 != side3 && side2 == side4))) {
            throw BadFigure("It's not a Trapezoid");
        }
    }

    virtual Point<TPoint> CalculateCentroid() const override {
        Point<TPoint> firstPoint((topRight_.xCord + topLeft_.xCord) / 2, (topRight_.yCord + topLeft_.yCord) / 2);
        Point<TPoint> secondPoint((downRight_.xCord + downLeft_.xCord) / 2, (downRight_.yCord + downLeft_.yCord) / 2);
        TPoint lengthDegree = Point<TPoint>::Length(topLeft_, topRight_) > Point<TPoint>::Length(downLeft_, downRight_) 
                              ? Point<TPoint>::Length(firstPoint, secondPoint) / 3 
                              : (2 * Point<TPoint>::Length(firstPoint, secondPoint)) / 3;
        TPoint kLD = lengthDegree / Point<TPoint>::Length(firstPoint, secondPoint);
        TPoint xLengthDegree = std::abs(firstPoint.xCord - secondPoint.xCord) * kLD;
        TPoint yLengthDegree = std::abs(firstPoint.yCord - secondPoint.yCord) * kLD;
        return {firstPoint.xCord - xLengthDegree, firstPoint.yCord - yLengthDegree};
    }

    virtual double CalculateArea() const override {
        TPoint firstSide = Point<TPoint>::Length(topLeft_, topRight_);
        TPoint secondSide = Point<TPoint>::Length(downLeft_, downRight_);
        TPoint thirdSide = Point<TPoint>::Length(topLeft_, downLeft_);
        TPoint perimetrDevTwo = (firstSide + secondSide + 2 * thirdSide) / 2; 
        return std::sqrt((perimetrDevTwo - firstSide) * (perimetrDevTwo - secondSide) * std::pow((perimetrDevTwo - thirdSide), 2));
    }

    Trapezoid& operator= (const Trapezoid& other) {
        if (this != &other) {
            topLeft_ = other.topLeft_;
            topRight_ = other.topRight_;
            downRight_ = other.downRight_;
            downLeft_ = other.downLeft_;
        }
        return *this;
    }

    Trapezoid& operator= (Trapezoid&& other) noexcept {
        if (this != &other) {
            topLeft_ = std::move(other.topLeft_);
            topRight_ = std::move(other.topRight_);
            downRight_ = std::move(other.downRight_);
            downLeft_ = std::move(other.downLeft_);
        }
        return *this;
    }

    bool operator==(const Trapezoid& other) const {
        return topLeft_ == other.topLeft_ &&
               topRight_ == other.topRight_ &&
               downRight_ == other.downRight_ &&
               downLeft_ == other.downLeft_;
    }

    virtual operator double() const override {
        return CalculateArea();
    }

    Point<TPoint> GetTopLeft() const { return topLeft_; }
    Point<TPoint> GetTopRight() const { return topRight_; }
    Point<TPoint> GetDownRight() const { return downRight_; }
    Point<TPoint> GetDownLeft() const { return downLeft_; }

    virtual ~Trapezoid() override {}

public:
    template <typename TStreamPoint>
    friend std::istream& operator>>(std::istream& is, Trapezoid<TStreamPoint>& trap);

    template <typename TStreamPoint>
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid<TStreamPoint>& trap);

protected:
    Point<TPoint> topLeft_;
    Point<TPoint> topRight_;
    Point<TPoint> downRight_;
    Point<TPoint> downLeft_;
};

template <typename TStreamPoint>
std::istream& operator>>(std::istream& is, Trapezoid<TStreamPoint>& trap) {
    is >> trap.topLeft_ >> trap.topRight_ >> trap.downRight_ >> trap.downLeft_;
    trap.ChangeArrangementIfBad();
    trap.CheckOnRightFigure();
    return is;
}

template <typename TStreamPoint>
std::ostream& operator<<(std::ostream& os, const Trapezoid<TStreamPoint>& trap) {
    os << trap.topLeft_ << " " << trap.topRight_ << " " << trap.downRight_ << " " << trap.downLeft_;
    return os;
}

#endif