cmake_minimum_required(VERSION 3.5)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

project(Cadmium)
set(Cadmium_VERSION_MAJOR 0)
set(Cadmium_VERSION_MINOR 1)

configure_file(
  ${PROJECT_SOURCE_DIR}/Version.hpp.in
  ${PROJECT_BINARY_DIR}/Version.hpp
)

find_package(Clang REQUIRED)
find_package(LLVM REQUIRED CONFIG 7.0)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
llvm_map_components_to_libnames(LLVM_LIBRARIES core irreader option profiledata codegen coverage passes objcarcopts coroutines lto)

link_directories(${Clang_LIBRARY_DIR})

add_executable(Cadmium Core.cpp)
target_include_directories(Cadmium PUBLIC
  ${PROJECT_BINARY_DIR}
  ${Clang_INCLUDE_DIRS}
)

target_link_libraries(Cadmium ${Clang_LIBRARIES} ${LLVM_LIBRARIES})
