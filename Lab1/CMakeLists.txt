cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Pogozhev Maxim" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "Объектно-ориентированное программирование, lab №1" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
