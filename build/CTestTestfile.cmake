# CMake generated Testfile for 
# Source directory: C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3
# Build directory: C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RectangleTest "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/build/lab_3_tests.exe")
set_tests_properties(RectangleTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;63;add_test;C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;0;")
add_test(SquareTest "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/build/lab_3_tests.exe")
set_tests_properties(SquareTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;64;add_test;C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;0;")
add_test(TrapezoidTest "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/build/lab_3_tests.exe")
set_tests_properties(TrapezoidTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;65;add_test;C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;0;")
add_test(FigureTest "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/build/lab_3_tests.exe")
set_tests_properties(FigureTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;66;add_test;C:/Users/CrazyBlackFire/Documents/Code/oop/Lab3/CMakeLists.txt;0;")
subdirs("googletest")
