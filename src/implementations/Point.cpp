#include "Point.hpp"

template <typename T>
Point<T>::Point() : xCord(0), yCord(0) {}

template <typename T>
Point<T>::Point(ValueType xCord, ValueType yCord) : xCord(xCord), yCord(yCord) {}

template <typename T>
Point<T>::Point(const Point& other) : xCord(other.xCord), yCord(other.yCord) {}

template <typename T>
Point<T>::Point(Point&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

template <typename T>
typename Point<T>::ValueType Point<T>::GetX() const {
    return xCord;
}

template <typename T>
typename Point<T>::ValueType Point<T>::GetY() const {
    return yCord;
}

template <typename T>
Point<T>& Point<T>::operator= (const Point& other) {
    if (this != &other) {
        xCord = other.xCord;
        yCord = other.yCord;
    }
    return *this;
}

template <typename T>
Point<T>& Point<T>::operator= (Point&& other) noexcept {
    if (this != &other) {
        xCord = std::move(other.xCord);
        yCord = std::move(other.yCord);
    }
    return *this;
}

template <typename T>
bool Point<T>::operator==(const Point& other) const {
    const double epsilon = 1e-9;
    return std::abs(static_cast<double>(xCord) - static_cast<double>(other.xCord)) < epsilon &&
           std::abs(static_cast<double>(yCord) - static_cast<double>(other.yCord)) < epsilon;
}

template <typename T>
double Point<T>::Length(const Point& point1, const Point& point2) {
    return std::sqrt(std::pow(static_cast<double>(point1.xCord - point2.xCord), 2) +
                     std::pow(static_cast<double>(point1.yCord - point2.yCord), 2));
}

template <typename T>
Point<T> Point<T>::operator/(ValueType scalar) const {
    return Point(xCord / scalar, yCord / scalar);
}

template <typename T>
Point<T> Point<T>::operator+(const Point& other) const {
    return Point(xCord + other.xCord, yCord + other.yCord);
}

template <typename T>
Point<T> Point<T>::operator-(const Point& other) const {
    return Point(xCord - other.xCord, yCord - other.yCord);
}

template <typename T>
bool Point<T>::operator>(const Point& other) const {
    return xCord > other.xCord || yCord > other.yCord;
}

template <typename T>
bool Point<T>::operator<(const Point& other) const {
    return xCord < other.xCord || yCord < other.yCord;
}

template <typename T>
void swap(Point<T>& a, Point<T>& b) {
    using std::swap;
    swap(a.xCord, b.xCord);
    swap(a.yCord, b.yCord);
}

template <typename TPoint>
std::istream& operator>>(std::istream& is, Point<TPoint>& point) {
    is >> point.xCord >> point.yCord;
    return is;
}

template <typename TPoint>
std::ostream& operator<<(std::ostream& os, const Point<TPoint>& point) {
    os << "(" << point.xCord << ", " << point.yCord << ")";
    return os;
}

template class Point<double>;
template std::istream& operator>><double>(std::istream&, Point<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Point<double>&);
template void swap<double>(Point<double>&, Point<double>&);