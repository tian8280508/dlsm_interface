cmake_minimum_required(VERSION 3.0)
# Keep the version below in sync with the one in db.h
project(dlsm_interface VERSION 1.22.0 LANGUAGES C CXX)

message("${CMAKE_SOURCE_DIR}")
include_directories(${CMAKE_SOURCE_DIR}/../dLSM)
include_directories(${CMAKE_SOURCE_DIR}/../dLSM/include)
find_library(IBVERBS_LIBRARY ibverbs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED OFF)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(dlsm_interface src/main.cpp)

find_library(NUMA_LIBRARY numa)
find_library(SNAPPY_LIBRARY snappy)
find_library(IBVERBS_LIBRARY ibverbs)
target_link_libraries(dlsm_interface ${CMAKE_SOURCE_DIR}/../dLSM/build/libTimberSaw.a)
target_link_libraries(dlsm_interface ${IBVERBS_LIBRARY} ${NUMA_LIBRARY} ${SNAPPY_LIBRARY})