add_executable(UpdatedStringTest test_my_lab.cpp)

target_link_libraries(UpdatedStringTest
  PRIVATE
    GTest::GTest
    UpdatedString)

add_test(UpdatedStringGTest UpdatedStringTest)