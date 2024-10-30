#include "Trapezoid.hpp"

template<typename TPoint>
static bool ComparePoints(const Vector<TPoint>& startPoint, const Point<TPoint>& p1, const Point<TPoint>& p2) {
    TPoint angle2 = Vector<TPoint>::Angle(startPoint, Vector<TPoint>(p2));
    TPoint angle1 = Vector<TPoint>::Angle(startPoint, Vector<TPoint>(p1));
    return angle1 < angle2;
}

template <typename TPoint>
Trapezoid<TPoint>::Trapezoid() : topLeft_(0, 0), topRight_(0, 0), downRight_(0, 0), downLeft_(0, 0) {}

template <typename TPoint>
Trapezoid<TPoint>::Trapezoid(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
    : topLeft_(topLeft), topRight_(topRight), downRight_(downRight), downLeft_(downLeft) {
    ChangeArrangementIfBad();
    SetSize();
    CheckOnRightFigure();
}

template <typename TPoint>
Trapezoid<TPoint>::Trapezoid(const Trapezoid& other)
    : topLeft_(other.topLeft_), topRight_(other.topRight_), downRight_(other.downRight_), downLeft_(other.downLeft_) {}

template <typename TPoint>
Trapezoid<TPoint>::Trapezoid(Trapezoid&& other) noexcept
    : topLeft_(std::move(other.topLeft_)),
      topRight_(std::move(other.topRight_)),
      downRight_(std::move(other.downRight_)),
      downLeft_(std::move(other.downLeft_)) {}

template <typename TPoint>
Point<TPoint> Trapezoid<TPoint>::GetTopLeft() const { return topLeft_; }

template <typename TPoint>
Point<TPoint> Trapezoid<TPoint>::GetTopRight() const { return topRight_; }

template <typename TPoint>
Point<TPoint> Trapezoid<TPoint>::GetDownRight() const { return downRight_; }

template <typename TPoint>
Point<TPoint> Trapezoid<TPoint>::GetDownLeft() const { return downLeft_; }

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Trapezoid<TPoint>::Clone() const {
    return std::make_unique<Trapezoid>(*this);
}

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Trapezoid<TPoint>::Move() noexcept {
    return std::make_unique<Trapezoid>(std::move(*this));
}

template <typename TPoint>
void Trapezoid<TPoint>::ChangeArrangementIfBad() {
    TPoint eps = 1e-9;

    std::vector<Point<TPoint>> pointsToSort {topLeft_, topRight_, downRight_, downLeft_};
    std::sort(pointsToSort.begin(), pointsToSort.end());
    Vector<TPoint> startPoint(pointsToSort[0]);
    std::sort(pointsToSort.begin(), pointsToSort.end(), [startPoint](const Point<TPoint>& p1, const Point<TPoint>& p2) {
        return ComparePoints(startPoint, p1, p2);
    });
    
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
        }
    } else if (isParallel2) {
        if (Vector<TPoint>::Length(vec2) > Vector<TPoint>::Length(vec4)) {
            std::swap(downLeft_, topRight_);
        } else {
            std::swap(downRight_, topLeft_);
        }
    }
}

template <typename TPoint>
void Trapezoid<TPoint>::CheckOnRightFigure() {
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

template <typename TPoint>
void Trapezoid<TPoint>::SetSize() {
    TPoint firstSide = Point<TPoint>::Length(topLeft_, topRight_);
    TPoint secondSide = Point<TPoint>::Length(topRight_, downRight_);
    TPoint thirdSide = Point<TPoint>::Length(downRight_, downLeft_);
    TPoint fourthSide = Point<TPoint>::Length(downLeft_, topRight_);
    size_ = {firstSide, secondSide, thirdSide, fourthSide};
}

template <typename TPoint>
TPoint Trapezoid<TPoint>::CalculateHeight() const {
    Vector<TPoint> vec1 = topRight_ - topLeft_;
    Vector<TPoint> perpendicularVec = Vector<TPoint>::Perpendicular(vec1);

    TPoint distance = std::abs(Vector<TPoint>::DotProduct(perpendicularVec, Vector<TPoint>(topLeft_, downLeft_))) / Vector<TPoint>::Length(perpendicularVec);

    return distance;
}

template <typename TPoint>
Point<TPoint> Trapezoid<TPoint>::CalculateCentroid() const {
    TPoint xCordCentroid = (topLeft_.GetX() + topRight_.GetX() + downRight_.GetX() + downLeft_.GetX()) / 4;
    TPoint yCordCentroid = (topLeft_.GetY() + topRight_.GetY() + downRight_.GetY() + downLeft_.GetY()) / 4;
    return Point<TPoint>(xCordCentroid, yCordCentroid);
}

template <typename TPoint>
double Trapezoid<TPoint>::CalculateArea() const {
    TPoint firstSide = size_[0];
    TPoint secondSide = size_[2];
    TPoint height = CalculateHeight(); 
    return ((firstSide + secondSide) / 2) * height;
}

template <typename TPoint>
Trapezoid<TPoint>& Trapezoid<TPoint>::operator=(const Trapezoid& other) {
    if (this != &other) {
        topLeft_ = other.topLeft_;
        topRight_ = other.topRight_;
        downRight_ = other.downRight_;
        downLeft_ = other.downLeft_;
    }
    return *this;
}

template <typename TPoint>
Trapezoid<TPoint>& Trapezoid<TPoint>::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        topLeft_ = std::move(other.topLeft_);
        topRight_ = std::move(other.topRight_);
        downRight_ = std::move(other.downRight_);
        downLeft_ = std::move(other.downLeft_);
    }
    return *this;
}

template <typename TPoint>
bool Trapezoid<TPoint>::operator==(const Trapezoid& other) const {
    return topLeft_ == other.topLeft_ &&
           topRight_ == other.topRight_ &&
           downRight_ == other.downRight_ &&
           downLeft_ == other.downLeft_;
}

template <typename TPoint>
Trapezoid<TPoint>::operator double() const {
    return CalculateArea();
}

template <typename TPoint>
Trapezoid<TPoint>::~Trapezoid() {}

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

template class Trapezoid<double>;
template std::istream& operator>><double>(std::istream&, Trapezoid<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Trapezoid<double>&);
