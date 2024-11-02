cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Погожев Максим" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабороторная работа номер 4, вариант 18" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include_directories(includes)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set(
    TEST_SOURCES
    test/test_main.cpp
    test/test_rectangle/test_double.cpp
    test/test_rectangle/test_int.cpp
    test/test_square/test_double.cpp
    test/test_square/test_int.cpp
    test/test_trapezoid/test_double.cpp
    test/test_trapezoid/test_int.cpp
    test/test_figure/test_double.cpp
    test/test_figure/test_int.cpp
    includes/figures/Rectangle.hpp
    includes/figures/Trapezoid.hpp
    includes/figures/Square.hpp
    includes/coordinates/Point.hpp
    includes/coordinates/Vector.hpp
    includes/Array.hpp
    includes/concepts/ArithmeticConcept.hpp
    src/implementations/Point.cpp
    src/implementations/Vector.cpp
    src/implementations/Rectangle.cpp
    src/implementations/Square.cpp
    src/implementations/Trapezoid.cpp
)

add_executable(
    lab_4_tests
    ${TEST_SOURCES}
)

target_include_directories(
    lab_4_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    lab_4_tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME RectangleTest COMMAND lab_4_tests)
add_test(NAME SquareTest COMMAND lab_4_tests)
add_test(NAME TrapezoidTest COMMAND lab_4_tests)
add_test(NAME FigureTest COMMAND lab_4_tests)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_4_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        lab_4_tests PRIVATE
        -Wall
        -Wextra
        -Wcast-align
        -Wconversion
        # -Wsign-conversion
        -Wfloat-equal
        -Wpedantic
        -Werror
        -pedantic
        -O2
    )
endif()
