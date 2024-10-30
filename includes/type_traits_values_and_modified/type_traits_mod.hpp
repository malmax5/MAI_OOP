#ifndef TYPE_TRAITS_MOD_HPP
#define TYPE_TRAITS_MOD_HPP

#include <type_traits>
#include "type_traits_v.hpp"

template<class T>
struct is_integral_excluding_char : std::integral_constant<bool,
                                                is_integral_v<T> &&
                                                !is_same_v<T, char> &&
                                                !is_same_v<T, signed char> &&
                                                !is_same_v<T, unsigned char> >
{};

template<class T>
constexpr bool is_integral_excluding_char_v = is_integral_excluding_char<T>::value;

#endif