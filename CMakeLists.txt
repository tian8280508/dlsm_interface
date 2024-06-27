cmake_minimum_required(VERSION 3.0)
# Keep the version below in sync with the one in db.h
project(dlsm_interface VERSION 1.22.0 LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/pb)

set(DLSM_DIR "/home/tjz/vscode_workspace/dLSM")
include_directories(${DLSM_DIR})
include_directories(${DLSM_DIR}/include)

set(GRPC_INSTALL_DIR "/home/tjz/my_grpc")
include_directories(${GRPC_INSTALL_DIR}/include)
link_directories(${GRPC_INSTALL_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED OFF)
set(CMAKE_C_EXTENSIONS OFF)

# 找到Protobuf
# find_package(Protobuf REQUIRED)
# include_directories(${Protobuf_INCLUDE_DIRS})
# find_package(gRPC CONFIG REQUIRED)
# include_directories(${gRPC_INCLUDE_DIRS})

file(GLOB PROTO_SRCS ${CMAKE_SOURCE_DIR}/pb/*.pb.cc)
file(GLOB GRPC_SRCS ${CMAKE_SOURCE_DIR}/pb/*.grpc.pb.cc)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(dlsm_interface ${SRC_FILES} ${PROTO_SRCS} ${GRPC_SRCS})

find_library(NUMA_LIBRARY numa)
find_library(SNAPPY_LIBRARY snappy)
find_library(IBVERBS_LIBRARY ibverbs)

target_link_libraries(dlsm_interface ${DLSM_DIR}/build/libTimberSaw.a)
target_link_libraries(dlsm_interface ${IBVERBS_LIBRARY} ${NUMA_LIBRARY} ${SNAPPY_LIBRARY})
# target_link_libraries(dlsm_interface gRPC::grpc++ protobuf::libprotobuf)