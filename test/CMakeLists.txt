cmake_minimum_required(VERSION 3.7.2)

include_directories(../include)
include_directories(../src/internal-header)

link_directories(../build/src/)

add_executable(main_test main_test.cc)

target_link_libraries(main_test libfgrep)
