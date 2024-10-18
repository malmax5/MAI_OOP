# CMake generated Testfile for 
# Source directory: /home/cbf/MAI/OOP/Lab_3
# Build directory: /home/cbf/MAI/OOP/Lab_3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RectangleTest "/home/cbf/MAI/OOP/Lab_3/build/lab_3_tests")
set_tests_properties(RectangleTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;69;add_test;/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;0;")
add_test(SquareTest "/home/cbf/MAI/OOP/Lab_3/build/lab_3_tests")
set_tests_properties(SquareTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;70;add_test;/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;0;")
add_test(TrapezoidTest "/home/cbf/MAI/OOP/Lab_3/build/lab_3_tests")
set_tests_properties(TrapezoidTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;71;add_test;/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;0;")
add_test(FigureTest "/home/cbf/MAI/OOP/Lab_3/build/lab_3_tests")
set_tests_properties(FigureTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;72;add_test;/home/cbf/MAI/OOP/Lab_3/CMakeLists.txt;0;")
subdirs("googletest")
