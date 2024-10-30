# CMake generated Testfile for 
# Source directory: /home/cbf/MAI/OOP/Lab_4
# Build directory: /home/cbf/MAI/OOP/Lab_4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RectangleTest "/home/cbf/MAI/OOP/Lab_4/build/lab_4_tests")
set_tests_properties(RectangleTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;59;add_test;/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;0;")
add_test(SquareTest "/home/cbf/MAI/OOP/Lab_4/build/lab_4_tests")
set_tests_properties(SquareTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;60;add_test;/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;0;")
add_test(TrapezoidTest "/home/cbf/MAI/OOP/Lab_4/build/lab_4_tests")
set_tests_properties(TrapezoidTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;61;add_test;/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;0;")
add_test(FigureTest "/home/cbf/MAI/OOP/Lab_4/build/lab_4_tests")
set_tests_properties(FigureTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;62;add_test;/home/cbf/MAI/OOP/Lab_4/CMakeLists.txt;0;")
subdirs("googletest")
