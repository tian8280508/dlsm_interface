cmake_minimum_required(VERSION 3.0)
# Keep the version below in sync with the one in db.h
project(dlsm_forward VERSION 1.22.0 LANGUAGES C CXX)

message("${CMAKE_SOURCE_DIR}")
include_directories(${CMAKE_SOURCE_DIR}/../dLSM/include)

set(CMAKE_CXX_STANDARD 11)

add_executable(dlsm_forward src/main.cpp)

target_link_libraries(dlsm_forward ${CMAKE_SOURCE_DIR}/../dLSM/build/libTimberSaw.a)