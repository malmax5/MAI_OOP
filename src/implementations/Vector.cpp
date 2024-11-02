#include "../../includes/coordinates/Vector.hpp"

#include "../../includes/concepts/ArithmeticConcept.hpp"

template <Arithmetic T>
Vector<T>::Vector() : xCord(0), yCord(0) {}

template <Arithmetic T>
Vector<T>::Vector(ValueType xCord, ValueType yCord) : xCord(xCord), yCord(yCord) {}

template <Arithmetic T>
Vector<T>::Vector(const Point<ValueType>& start, const Point<ValueType>& end) 
    : xCord(end.GetX() - start.GetX()), yCord(end.GetY() - start.GetY()) {}

template <Arithmetic T>
Vector<T>::Vector(const Point<ValueType>& other) : xCord(other.GetX()), yCord(other.GetY()) {}

template <Arithmetic T>
Vector<T>::Vector(Point<ValueType>&& other) noexcept : xCord(other.GetX()), yCord(other.GetY()) {}

template <Arithmetic T>
Vector<T>::Vector(const Vector& other) : xCord(other.xCord), yCord(other.yCord) {}

template <Arithmetic T>
Vector<T>::Vector(Vector&& other) noexcept : xCord(std::move(other.xCord)), yCord(std::move(other.yCord)) {}

template <Arithmetic T>
typename Vector<T>::ValueType Vector<T>::GetX() const { 
    return xCord; 
}

template <Arithmetic T>
typename Vector<T>::ValueType Vector<T>::GetY() const { 
    return yCord; 
}

template <Arithmetic T>
double Vector<T>::Length(const Vector& vec) {
    return std::sqrt(vec.xCord * vec.xCord + vec.yCord * vec.yCord);
}

template <Arithmetic T>
typename Vector<T>::ValueType Vector<T>::DotProduct(const Vector& vec1, const Vector& vec2) {
    return vec1.xCord * vec2.xCord + vec1.yCord * vec2.yCord;
}

template <Arithmetic T>
typename Vector<T>::ValueType Vector<T>::CrossProduct(const Vector& vec1, const Vector& vec2) {
    return vec1.xCord * vec2.yCord - vec1.yCord * vec2.xCord;
}

template <Arithmetic T>
Vector<T> Vector<T>::Perpendicular(const Vector& vec) {
    return Vector(vec.yCord, -vec.xCord);
}

template <Arithmetic T>
double Vector<T>::Angle(const Vector& startVector, const Vector& endVector) {
    return std::atan2(endVector.yCord - startVector.yCord, endVector.xCord - startVector.xCord);
}

template <Arithmetic T>
Vector<T>& Vector<T>::operator= (const Vector& other) {
    if (this != &other) {
        xCord = other.xCord;
        yCord = other.yCord;
    }
    return *this;
}

template <Arithmetic T>
Vector<T>& Vector<T>::operator= (Vector&& other) noexcept {
    if (this != &other) {
        xCord = std::move(other.xCord);
        yCord = std::move(other.yCord);
    }
    return *this;
}

template <Arithmetic T>
bool Vector<T>::operator==(const Vector& other) const {
    bool res = 0;
    const double eps = 1e-9;
    if constexpr (std::is_floating_point<T>::value)
        res = (std::fabs(xCord - other.xCord) < eps) && (std::fabs(yCord - other.yCord) < eps);
    else
        res = (xCord == other.xCord) && (yCord == other.yCord);
    
    return res;
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

template class Vector<int>;
template std::istream& operator>><int>(std::istream&, Vector<int>&);
template std::ostream& operator<< <int>(std::ostream&, const Vector<int>&);
