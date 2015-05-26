project(coreutils)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#aux_source_directory(. SRC_LIST)
add_executable(echo echo.cpp)
add_executable(cat cat.cpp)
add_executable(_test test/main.cpp test/utils.cpp test/test_echo.cpp test/test_cat.cpp)
