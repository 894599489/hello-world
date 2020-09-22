cmake_minimum_required(VERSION 2.8)

project(hello_world)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_STANDARD 17)

set(MY_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src)