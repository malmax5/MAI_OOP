#include "Vector.hpp"

template <typename T>
Vector<T>::Vector() : xCord(0), yCord(0) {}

template <typename T>
Vector<T>::Vector(ValueType xCord, ValueType yCord) : xCord(xCord), yCord(yCord) {}

template <typename T>
Vector<T>::Vector(const Point<ValueType>& start, const Point<ValueType>& end) 
    : xCord(end.GetX() - start.GetX()), yCord(end.GetY() - start.GetY()) {}

template <typename T>
Vector<T>::Vector(const Point<ValueType>& other) : xCord(other.GetX()), yCord(other.GetY()) {}

template <typename T>
Vector<T>::Vector(Point<ValueType>&& other) noexcept : xCord(other.GetX()), yCord(other.GetY()) {}

template <typename T>
Vector<T>::Vector(const Vector& other) : xCord(other.xCord), yCord(other.yCord) {}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

template <typename T>
typename Vector<T>::ValueType Vector<T>::GetX() const { 
    return xCord; 
}

template <typename T>
typename Vector<T>::ValueType Vector<T>::GetY() const { 
    return yCord; 
}

template <typename T>
typename Vector<T>::ValueType Vector<T>::Length(const Vector& vec) {
    return std::sqrt(vec.xCord * vec.xCord + vec.yCord * vec.yCord);
}

template <typename T>
typename Vector<T>::ValueType Vector<T>::DotProduct(const Vector& vec1, const Vector& vec2) {
    return vec1.xCord * vec2.xCord + vec1.yCord * vec2.yCord;
}

template <typename T>
typename Vector<T>::ValueType Vector<T>::CrossProduct(const Vector& vec1, const Vector& vec2) {
    return vec1.xCord * vec2.yCord - vec1.yCord * vec2.xCord;
}

template <typename T>
Vector<T> Vector<T>::Perpendicular(const Vector& vec) {
    return Vector(vec.yCord, -vec.xCord);
}

template <typename T>
double Vector<T>::Angle(const Vector& startVector, const Vector& endVector) {
    return std::atan2(endVector.yCord - startVector.yCord, endVector.xCord - startVector.xCord);
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector& other) {
    if (this != &other) {
        xCord = other.xCord;
        yCord = other.yCord;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator= (Vector&& other) noexcept {
    if (this != &other) {
        xCord = std::move(other.xCord);
        yCord = std::move(other.yCord);
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const {
    const double eps = 1e-9;
    return (std::abs(xCord - other.xCord) < eps) && (std::abs(yCord - other.yCord) < eps);
}

template <typename TVector>
std::istream& operator>>(std::istream& is, Vector<TVector>& vec) {
    is >> vec.xCord >> vec.yCord;
    return is;
}

template <typename TVector>
std::ostream& operator<<(std::ostream& os, const Vector<TVector>& vec) {
    os << "(" << vec.xCord << ", " << vec.yCord << ")";
    return os;
}

template class Vector<double>;
template std::istream& operator>><double>(std::istream&, Vector<double>&);
template std::ostream& operator<< <double>(std::ostream&, const Vector<double>&);