add_subdirectory(/usr/src/gtest
                ${PROJECT_BINARY_DIR}/gtest)
include(CTest)                
add_executable(test_weather test.cpp)
target_link_libraries(test_weather
                    weather
                    gtest gtest_main)
add_test(test_weather tests/test.cpp)