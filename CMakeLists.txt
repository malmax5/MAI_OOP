cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Погожев Максим" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "crazyblackfire@mail.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабороторная работа номер 4, вариант 18" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# include_directories(includes)

# add_subdirectory(
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
#     "googletest"
# )

set(
    TEST_SOURCES
    #main
    main.cpp

    #hpp
    #equip
    include/Equipment/Builder/equip_material_builder_main.hpp
    include/Equipment/Equip/Base/equip.hpp
    include/Equipment/Equip/Builder/Equip_Builder/equip_builder_interface.hpp
    include/Equipment/Equip/Builder/Equip_Builder/equip_builder.hpp
    include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_interface.hpp
    include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.hpp
    include/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder.hpp
    include/Equipment/Equip/Derived/boots.hpp
    include/Equipment/Equip/Derived/chestplate.hpp
    include/Equipment/Equip/Derived/helmet.hpp
    include/Equipment/Factory/equipment_factory.hpp
    include/Equipment/Equip/my_equip.hpp
    #material
    include/Equipment/Material/Base/material.hpp
    include/Equipment/Material/Derived/dimond.hpp
    include/Equipment/Material/Derived/gold.hpp
    include/Equipment/Material/Derived/iron.hpp
    include/Equipment/Material/Derived/decorative.hpp
    include/Equipment/Material/Derived/no_material.hpp

    #cpp
    #equip
    src/implementations/Equipment/Builder/equip_material_builder_main.cpp
    src/implementations/Equipment/Equip/Base/equip.cpp
    src/implementations/Equipment/Equip/Builder/Equip_Builder/equip_builder_interface.cpp
    src/implementations/Equipment/Equip/Builder/Equip_Builder/equip_builder.cpp
    src/implementations/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_interface.cpp
    src/implementations/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder_main.cpp
    src/implementations/Equipment/Equip/Builder/MyEquip_Builder/myequip_builder.cpp
    src/implementations/Equipment/Equip/Derived/boots.cpp
    src/implementations/Equipment/Equip/Derived/chestplate.cpp
    src/implementations/Equipment/Equip/Derived/helmet.cpp
    src/implementations/Equipment/Equip/my_equip.cpp
    #material
    src/implementations/Equipment/Material/Base/material.cpp
    src/implementations/Equipment/Material/Derived/dimond.cpp
    src/implementations/Equipment/Material/Derived/gold.cpp
    src/implementations/Equipment/Material/Derived/iron.cpp
    src/implementations/Equipment/Material/Derived/decorative.cpp
    src/implementations/Equipment/Material/Derived/no_material.cpp

    #logger
    Log/log.hpp
)

add_executable(
    lab_6_tests
    ${TEST_SOURCES}
)

# target_include_directories(
#     lab_6_tests PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
# )

# target_link_libraries(
#     lab_6_tests
#     gtest 
#     gtest_main
# )

# enable_testing()

# add_test(NAME MapMemoryResourceTest COMMAND lab_6_tests)
# add_test(NAME ForwardListTest COMMAND lab_6_tests)

if (MSVC)
    # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_6_tests PRIVATE
        # /W4
    )
else ()
    target_compile_options(
        lab_6_tests PRIVATE
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
