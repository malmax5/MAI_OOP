#ifndef TYPE_TRAITS_V_HPP
#define TYPE_TRAITS_V_HPP

#include<type_traits>

template<class T, class U>
constexpr bool is_same_v = std::is_same<T, U>::value;

template<class T>
constexpr bool is_integral_v = std::is_integral<T>::value;

template<class T>
constexpr bool is_floating_point_v = std::is_floating_point<T>::value;

#endif