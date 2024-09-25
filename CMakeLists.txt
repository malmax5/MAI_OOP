cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Погожев Максим" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабороторная работа номер 2, вариант 4" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(includes)

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set(
    SOURCES
    main.cpp
    src/implementations/Vector.cpp
    includes/implementations/Vector.h
    src/implementations/FourCalc.cpp
    includes/interfaces/Ifour.h
    includes/implementations/FourCalc.h
)

set(
    SOURCES
    main.cpp
    src/implementations/Vector.cpp
    includes/implementations/Vector.h
    src/implementations/FourCalc.cpp
    includes/implementations/FourCalc.h
    includes/interfaces/IFour.h
)

set(
    TEST_SOURCES
    test/test_main.cpp
    test/test_lab_2.cpp
    src/implementations/Vector.cpp
    includes/implementations/Vector.h
    src/implementations/FourCalc.cpp
    includes/implementations/FourCalc.h
    includes/interfaces/IFour.h
)

add_executable(
    lab_2
    ${SOURCES}
)

add_executable(
    lab_2_tests
    ${TEST_SOURCES}
)

target_include_directories(
    lab_2_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    lab_2_tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME ProjectTests COMMAND lab_1_tests)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_2 PRIVATE
        /W4
    )
    target_compile_options(
        lab_2_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        lab_2 PRIVATE
        # -Wall
        # -Wextra
        # -Wshadow
        # -Wcast-align
        # -Wconversion
        # -Wsign-conversion
        # -Wfloat-equal
        # -Wpedantic
        # -Werror
        # -pedantic
        # -O2
    )
    target_compile_options(
        lab_2_tests PRIVATE
        # -Wall
        # -Wextra
        # -Wshadow
        # -Wcast-align
        # -Wconversion
        # -Wsign-conversion
        # -Wfloat-equal
        # -Wpedantic
        # -Werror
        # -pedantic
        # -O2
    )
endif()
