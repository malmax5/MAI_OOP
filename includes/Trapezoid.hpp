#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "../includes/Figure.hpp"
#include "../includes/Point.hpp"
#include "../includes/Vector.hpp"
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
        SetSize();
        CheckOnRightFigure();
    }
    Trapezoid(const Trapezoid& other)
        : topLeft_(other.topLeft_), topRight_(other.topRight_), downRight_(other.downRight_), downLeft_(other.downLeft_) {}
    Trapezoid(Trapezoid&& other) noexcept
        : topLeft_(std::move(other.topLeft_)),
          topRight_(std::move(other.topRight_)),
          downRight_(std::move(other.downRight_)),
          downLeft_(std::move(other.downLeft_)) {}

    Point<TPoint> GetTopLeft() const { return topLeft_; }
    Point<TPoint> GetTopRight() const { return topRight_; }
    Point<TPoint> GetDownRight() const { return downRight_; }
    Point<TPoint> GetDownLeft() const { return downLeft_; }

    // virtual Trapezoid* Clone() const override { return new Trapezoid(*this); }
    // virtual Trapezoid* Move() noexcept override { return new Trapezoid(std::move(*this)); }

    static bool ComparePoints(const Vector<TPoint>& startPoint, const Point<TPoint>& p1, const Point<TPoint>& p2) {
        TPoint angle2 = Vector<TPoint>::Angle(startPoint, Vector<TPoint>(p2));
        TPoint angle1 = Vector<TPoint>::Angle(startPoint, Vector<TPoint>(p1));
        return angle1 < angle2;
    }

    void ChangeArrangementIfBad() {
        TPoint eps = 1e-9;

        std::vector<Point<TPoint>> pointsToSort {topLeft_, topRight_, downRight_, downLeft_};
        sort(pointsToSort.begin(), pointsToSort.end());
        Vector<TPoint> startPoint(pointsToSort[0]);
        sort(pointsToSort.begin(), pointsToSort.end(), [startPoint](const Point<TPoint>& p1, const Point<TPoint>& p2)
                                                       { return ComparePoints(startPoint, p1, p2); });
        
        topLeft_ = std::move(pointsToSort[0]);
        topRight_ = std::move(pointsToSort[1]);
        downRight_ = std::move(pointsToSort[2]);
        downLeft_ = std::move(pointsToSort[3]);

        Vector<TPoint> vec1 = topRight_ - topLeft_;
        Vector<TPoint> vec2 = downRight_ - topRight_;
        Vector<TPoint> vec3 = downLeft_ - downRight_;
        Vector<TPoint> vec4 = topLeft_ - downLeft_;

        bool isParallel1 = (Vector<TPoint>::CrossProduct(vec1, vec3) < eps);
        bool isParallel2 = (Vector<TPoint>::CrossProduct(vec2, vec4) < eps);

        if (isParallel1) {
            if (Vector<TPoint>::Length(vec1) > Vector<TPoint>::Length(vec3)) {
                std::swap(downRight_, topRight_);
                std::swap(downLeft_, topLeft_);
            } // 1 2 3 4  1.(3 4)(1 2)
        } else if (isParallel2) {
            if (Vector<TPoint>::Length(vec2) > Vector<TPoint>::Length(vec4)) {
                std::swap(downLeft_, topRight_);
            } // 1 2 3 4  1.(4 1)(2 3)
            else {
                std::swap(downRight_, topLeft_);
            } // 1 2 3 4 1.(1 4)(2 3)
        }
    }

    virtual void CheckOnRightFigure() {
        TPoint eps = 1e-9;

        Vector<TPoint> vec1 = topRight_ - topLeft_;
        Vector<TPoint> vec2 = downRight_ - topRight_;
        Vector<TPoint> vec3 = downLeft_ - downRight_;
        Vector<TPoint> vec4 = topLeft_ - downLeft_;

        bool isParallel1 = (Vector<TPoint>::CrossProduct(vec1, vec3) < eps);
        bool isParallel2 = (Vector<TPoint>::CrossProduct(vec2, vec4) < eps);

        if (!(isParallel1 ^ isParallel2)) {
            throw BadFigure("It's not a Trapezoid");
        }
    }

    virtual void SetSize() {
        TPoint firstSide = Point<TPoint>::Length(topLeft_, topRight_);
        TPoint secondSide = Point<TPoint>::Length(topRight_, downRight_);
        TPoint thirdSide = Point<TPoint>::Length(downRight_, downLeft_);
        TPoint fourthSide = Point<TPoint>::Length(downLeft_, topRight_);
        size_ = {firstSide, secondSide, thirdSide, fourthSide};
    }

    TPoint CalculateHeight() const {
        Vector<TPoint> vec1 = topRight_ - topLeft_;

        Vector<TPoint> perpendicularVec = Vector<TPoint>::Perpendicular(vec1);

        TPoint distance = std::abs(Vector<TPoint>::DotProduct(perpendicularVec, Vector<TPoint>(topLeft_, downLeft_))) / Vector<TPoint>::Length(perpendicularVec);

        return distance;
    }

    Point<TPoint> CalculateCentroid() const {
        TPoint xCordCentroid = (topLeft_.GetX() + topRight_.GetX() + downRight_.GetX() + downLeft_.GetX()) / 4;
        TPoint yCordCentroid = (topLeft_.GetY() + topRight_.GetY() + downRight_.GetY() + downLeft_.GetY()) / 4;
        return Point<TPoint>(xCordCentroid, yCordCentroid);
    }

    virtual double CalculateArea() const override {
        TPoint firstSide = size_[0];
        TPoint secondSide = size_[2];
        TPoint height = CalculateHeight(); 
        return ((firstSide + secondSide) / 2) * height;
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

    virtual ~Trapezoid() override {}

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