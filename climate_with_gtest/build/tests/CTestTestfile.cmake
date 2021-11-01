# CMake generated Testfile for 
# Source directory: /home/gl-407/moderncpp_repo/moderncpp/climate_with_gtest/tests
# Build directory: /home/gl-407/moderncpp_repo/moderncpp/climate_with_gtest/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_weather "tests/test.cpp")
set_tests_properties(test_weather PROPERTIES  _BACKTRACE_TRIPLES "/home/gl-407/moderncpp_repo/moderncpp/climate_with_gtest/tests/CMakeLists.txt;8;add_test;/home/gl-407/moderncpp_repo/moderncpp/climate_with_gtest/tests/CMakeLists.txt;0;")
subdirs("../gtest")
