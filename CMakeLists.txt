# Copyright 2018 gRPC authors.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building helloworld.

cmake_minimum_required(VERSION 3.8)

project(dlsm C CXX)

include(./common.cmake)

set(DLSM_DIR "/home/tjz/vscode_workspace/dLSM")
include_directories(${DLSM_DIR})
include_directories(${DLSM_DIR}/include)

# Proto file
get_filename_component(dlsm_proto "../pb/store/dlsm.proto" ABSOLUTE)
get_filename_component(dlsm_proto_path "${dlsm_proto}" PATH)

# Generated sources
set(dlsm_proto_srcs "${CMAKE_SOURCE_DIR}/pb/dlsm.pb.cc")
set(dlsm_proto_hdrs "${CMAKE_SOURCE_DIR}/pb/dlsm.pb.h")
set(dlsm_grpc_srcs "${CMAKE_SOURCE_DIR}/pb/dlsm.grpc.pb.cc")
set(dlsm_grpc_hdrs "${CMAKE_SOURCE_DIR}/pb/dlsm.grpc.pb.h")
add_custom_command(
      OUTPUT "${dlsm_proto_srcs}" "${dlsm_proto_hdrs}" "${dlsm_grpc_srcs}" "${dlsm_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_SOURCE_DIR}/pb"
        --cpp_out "${CMAKE_SOURCE_DIR}/pb"
        -I "${dlsm_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${dlsm_proto}"
      DEPENDS "${dlsm_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_SOURCE_DIR}/pb")
include_directories("${CMAKE_SOURCE_DIR}/include")

# 创建一个库
add_library(dlsm_grpc_proto
  ${dlsm_proto_srcs}
  ${dlsm_proto_hdrs}
  ${dlsm_grpc_srcs}
  ${dlsm_grpc_hdrs})
target_link_libraries(dlsm_grpc_proto
  absl::check
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

find_library(NUMA_LIBRARY numa)
find_library(SNAPPY_LIBRARY snappy)
find_library(IBVERBS_LIBRARY ibverbs)

file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cc)
add_executable(dlsm_interface ${SRC_FILES})
target_link_libraries(dlsm_interface ${DLSM_DIR}/build/libTimberSaw.a)
target_link_libraries(dlsm_interface ${IBVERBS_LIBRARY} ${NUMA_LIBRARY} ${SNAPPY_LIBRARY})
target_link_libraries(dlsm_interface dlsm_grpc_proto absl::check absl::flags absl::log ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})
# Targets greeter_[async_](client|server)
# foreach(_target
#   greeter_client greeter_server
#   greeter_callback_client greeter_callback_server
#   greeter_async_client greeter_async_client2 greeter_async_server)
#   add_executable(${_target} "${_target}.cc")
#   target_link_libraries(${_target}
#     hw_grpc_proto
#     absl::check
#     absl::flags
#     absl::flags_parse
#     absl::log
#     ${_REFLECTION}
#     ${_GRPC_GRPCPP}
#     ${_PROTOBUF_LIBPROTOBUF})
# endforeach()
