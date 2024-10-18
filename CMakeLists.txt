cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Погожев Максим" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабороторная работа номер 3, вариант 18" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(includes)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

# set(
#     SOURCES
#     main.cpp
#     src/implementations/Vector.cpp
#     includes/implementations/Vector.h
#     src/implementations/FourCalc.cpp
#     includes/interfaces/Ifour.h
#     includes/implementations/FourCalc.h
# )

set(
    TEST_SOURCES
    # test/test_main.cpp
    test/test_rectangle.cpp
    test/test_square.cpp
    test/test_trapezoid.cpp
    test/test_figure.cpp
    includes/Rectangle.hpp
    includes/Trapezoid.hpp
    includes/Square.hpp/
    includes/Point.hpp
    includes/Vector.hpp
    src/implementations/Point.cpp
    src/implementations/Vector.cpp
    src/implementations/Rectangle.cpp
    src/implementations/Square.cpp
    src/implementations/Trapezoid.cpp
)

# add_executable(
#     lab_3
#     ${SOURCES}
# )

add_executable(
    lab_3_tests
    ${TEST_SOURCES}
)

target_include_directories(
    lab_3_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    lab_3_tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME RectangleTest COMMAND lab_3_tests)
add_test(NAME SquareTest COMMAND lab_3_tests)
add_test(NAME TrapezoidTest COMMAND lab_3_tests)
add_test(NAME FigureTest COMMAND lab_3_tests)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_3_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        lab_3_tests PRIVATE
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
