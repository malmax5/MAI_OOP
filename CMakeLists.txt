cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Погожев Максим" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабороторная работа номер 4, вариант 18" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include_directories(includes)

# add_subdirectory(
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
#     "googletest"
# )

set(
    TEST_SOURCES
    # src/main_allocator.cpp
    src/main_forward_list.cpp

    # includes/allocators/extensions/map_memory_resource_adds.hpp
    # includes/allocators/map_memory_resource.hpp

    includes/forward_list/node.hpp
    includes/forward_list/forward_list.hpp
    src/forward_list/node.cpp
    src/forward_list/forward_list.cpp

    includes/forward_list/iterators/forward_list_iterator.hpp
    src/forward_list/iterators/forward_list_iterator.cpp
)

add_executable(
    lab_5_tests
    ${TEST_SOURCES}
)

# target_include_directories(
#     lab_5_tests PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
# )

# target_link_libraries(
#     lab_5_tests
#     gtest 
#     gtest_main
# )

# enable_testing()

# add_test(NAME RectangleTest COMMAND lab_5_tests)
# add_test(NAME SquareTest COMMAND lab_5_tests)
# add_test(NAME TrapezoidTest COMMAND lab_5_tests)
# add_test(NAME FigureTest COMMAND lab_5_tests)

if (MSVC)
    # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_5_tests PRIVATE
        # /W4
    )
else ()
    target_compile_options(
        lab_5_tests PRIVATE
        # -Wall
        # -Wextra
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
