project(climate)
cmake_minimum_required(VERSION 3.0)
include_directories(include)
add_library(weather lib/weather.cpp)
add_subdirectory(src)
enable_testing() #Must be called in top-most CmakeLists.txt
add_subdirectory(tests)
add_executable(main src/main.cpp)
target_link_libraries(main weather)
