#ifndef ARITHMETICCONCEPT_HPP
#define ARITHMETICCONCEPT_HPP

#include<iostream>
#include<concepts>
#include<type_traits>
#include "../type_traits_values_and_modified/type_traits_v.hpp"
#include "../type_traits_values_and_modified/type_traits_mod.hpp"

template<typename T>
concept Arithmetic = is_integral_excluding_char_v<T> ||
                     is_floating_point_v<T>;

#endif