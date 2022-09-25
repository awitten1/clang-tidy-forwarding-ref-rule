cmake_minimum_required(VERSION 3.13.4)
project(noexcept-move-constructor-rule-clang-tidy)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

message(STATUS "llvm include dirs: ${LLVM_INCLUDE_DIRS}")

if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

# Now build our tools
add_subdirectory(lib)
add_subdirectory(example)


