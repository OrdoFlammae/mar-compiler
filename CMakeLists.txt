cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(cpp-template)

add_executable(${PROJECT_NAME}
  src/main.cpp)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wmisleading-indentation
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wnull-dereference
    -Wuseless-cast
    -Wdouble-promotion
    -Wformat=2)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE include)
