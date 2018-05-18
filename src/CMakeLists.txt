cmake_minimum_required(VERSION 3.7.2)

include_directories(internal-header)
include_directories(../include)

add_library(libfgrep SHARED
  fgrep.cc
)

link_directories(./)

add_executable(fgrep
  main.cc
)

target_link_libraries(fgrep libfgrep)
