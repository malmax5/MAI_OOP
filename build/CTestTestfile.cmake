# CMake generated Testfile for 
# Source directory: /home/cbf/MAI/OOP/Lab_5
# Build directory: /home/cbf/MAI/OOP/Lab_5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MapMemoryResourceTest "/home/cbf/MAI/OOP/Lab_5/build/lab_5_tests")
set_tests_properties(MapMemoryResourceTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_5/CMakeLists.txt;56;add_test;/home/cbf/MAI/OOP/Lab_5/CMakeLists.txt;0;")
add_test(ForwardListTest "/home/cbf/MAI/OOP/Lab_5/build/lab_5_tests")
set_tests_properties(ForwardListTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_5/CMakeLists.txt;57;add_test;/home/cbf/MAI/OOP/Lab_5/CMakeLists.txt;0;")
subdirs("googletest")
