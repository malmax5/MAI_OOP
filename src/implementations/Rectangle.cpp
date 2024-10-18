#include "Rectangle.hpp"

template <typename TPoint>
Rectangle<TPoint>::Rectangle()
    : topLeft_(0, 0), topRight_(0, 0), downRight_(0, 0), downLeft_(0, 0) {}

template <typename TPoint>
Rectangle<TPoint>::Rectangle(Point<TPoint> topLeft, Point<TPoint> topRight, Point<TPoint> downRight, Point<TPoint> downLeft)
    : topLeft_(topLeft), topRight_(topRight), downRight_(downRight), downLeft_(downLeft) {
    ChangeArrangementIfBad();
    CheckOnRightFigure();
    SetSize();
}

template <typename TPoint>
Rectangle<TPoint>::Rectangle(const Rectangle& other)
    : topLeft_(other.topLeft_), topRight_(other.topRight_), downRight_(other.downRight_), downLeft_(other.downLeft_), size_(other.size_) {}

template <typename TPoint>
Rectangle<TPoint>::Rectangle(Rectangle&& other) noexcept
    : topLeft_(std::move(other.topLeft_)),
      topRight_(std::move(other.topRight_)),
      downRight_(std::move(other.downRight_)),
      downLeft_(std::move(other.downLeft_)),
      size_(std::move(other.size_)) {}

template <typename TPoint>
Point<TPoint> Rectangle<TPoint>::GetTopLeft() const { return topLeft_; }

template <typename TPoint>
Point<TPoint> Rectangle<TPoint>::GetTopRight() const { return topRight_; }

template <typename TPoint>
Point<TPoint> Rectangle<TPoint>::GetDownRight() const { return downRight_; }

template <typename TPoint>
Point<TPoint> Rectangle<TPoint>::GetDownLeft() const { return downLeft_; }

template <typename TPoint>
std::pair<TPoint, TPoint> Rectangle<TPoint>::GetSize() const { return size_; }

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Rectangle<TPoint>::Clone() const {
    return std::make_unique<Rectangle>(*this);
}

template <typename TPoint>
std::unique_ptr<Figure<TPoint>> Rectangle<TPoint>::Move() noexcept {
    return std::make_unique<Rectangle>(std::move(*this));
}

template <typename TPoint>
void Rectangle<TPoint>::ChangeArrangementIfBad() {
    std::vector<Point<TPoint>> goodArrangement {topLeft_, topRight_, downRight_, downLeft_};
    std::sort(goodArrangement.begin(), goodArrangement.end());
    topLeft_ = std::move(goodArrangement[2]);
    topRight_ = std::move(goodArrangement[3]);
    downRight_ = std::move(goodArrangement[1]);
    downLeft_ = std::move(goodArrangement[0]);
}

template <typename TPoint>
void Rectangle<TPoint>::CheckOnRightFigure() {
    TPoint eps = 1e-9;

    TPoint diag1 = Point<TPoint>::Length(topLeft_, downRight_);
    TPoint diag2 = Point<TPoint>::Length(topRight_, downLeft_);
    if (std::abs(diag1 - diag2) >= eps) {
        throw BadFigure("It's not a Rectangle");
    }
}

template <typename TPoint>
void Rectangle<TPoint>::SetSize() {
    TPoint firstSide = Point<TPoint>::Length(topLeft_, topRight_);
    TPoint secondSide = Point<TPoint>::Length(topLeft_, downLeft_);
    size_ = {firstSide, secondSide};
}

template <typename TPoint>
Point<TPoint> Rectangle<TPoint>::CalculateCentroid() const {
    TPoint xCord = (topLeft_.GetX() + topRight_.GetX()) / 2;
    TPoint yCord = (topLeft_.GetY() + downLeft_.GetY()) / 2;
    Point<TPoint> centroid(xCord, yCord);
    return centroid;
}

template <typename TPoint>
double Rectangle<TPoint>::CalculateArea() const {
    return size_.first * size_.second;
}

template <typename TPoint>
Rectangle<TPoint>& Rectangle<TPoint>::operator=(const Rectangle& other) {
    if (this != &other) {
        topLeft_ = other.topLeft_;
        topRight_ = other.topRight_;
        downRight_ = other.downRight_;
        downLeft_ = other.downLeft_;
        size_ = other.size_;
    }
    return *this;
}

template <typename TPoint>
Rectangle<TPoint>& Rectangle<TPoint>::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        topLeft_ = std::move(other.topLeft_);
        topRight_ = std::move(other.topRight_);
        downRight_ = std::move(other.downRight_);
        downLeft_ = std::move(other.downLeft_);
        size_ = std::move(other.size_);
    }
    return *this;
}

template <typename TPoint>
bool Rectangle<TPoint>::operator==(const Rectangle& other) const {
    return topLeft_ == other.topLeft_ &&
           topRight_ == other.topRight_ &&
           downRight_ == other.downRight_ &&
           downLeft_ == other.downLeft_;
}

template <typename TPoint>
Rectangle<TPoint>::operator double() const {
    return CalculateArea();
}

template <typename TPoint>
Rectangle<TPoint>::~Rectangle() {}

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

template class Rectangle<double>;
template std::istream& operator>><double>(std::istream&, Rectangle<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Rectangle<double>&);