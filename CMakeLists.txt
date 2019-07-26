cmake_minimum_required(VERSION 3.5)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

project(Cadmium)
set(Cadmium_VERSION_MAJOR 0)
set(Cadmium_VERSION_MINOR 1)

configure_file(
  ${PROJECT_SOURCE_DIR}/Version.hpp.in
  ${PROJECT_BINARY_DIR}/Version.hpp
)

find_package(LLVM REQUIRED CONFIG 7.0)
message(STATUS "Use LLVM ${LLVM_PACKAGE_VERSION}")

add_executable(Cadmium Core.cpp Figures.cpp)
target_include_directories(Cadmium PUBLIC ${PROJECT_BINARY_DIR})
