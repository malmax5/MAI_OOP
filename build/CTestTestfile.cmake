# CMake generated Testfile for 
# Source directory: /home/cbf/MAI/OOP/Lab_6
# Build directory: /home/cbf/MAI/OOP/Lab_6/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(EquipBuilderTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(EquipBuilderTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;196;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(MyEquipBuilderMainTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(MyEquipBuilderMainTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;197;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(MyEquipBuilderTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(MyEquipBuilderTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;198;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(EquipmentFactoryTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(EquipmentFactoryTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;199;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(SquirrelFactoryTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(SquirrelFactoryTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;200;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(KnightFactoryTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(KnightFactoryTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;201;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
add_test(PegasusFactoryTest "/home/cbf/MAI/OOP/Lab_6/build/lab_6_tests")
set_tests_properties(PegasusFactoryTest PROPERTIES  _BACKTRACE_TRIPLES "/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;202;add_test;/home/cbf/MAI/OOP/Lab_6/CMakeLists.txt;0;")
subdirs("gtest")
