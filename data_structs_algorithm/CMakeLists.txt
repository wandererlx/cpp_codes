cmake_minimum_required (VERSION 3.12)
project(cpp-tools)

add_compile_options(-std=c++17 -mavx2 -fno-elide-constructors)
file(GLOB_RECURSE SOURCES "./*.cc")

include_directories(include)
include_directories(./)

add_executable(cpp-tools ${SOURCES})
target_link_libraries(cpp-tools)