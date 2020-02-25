cmake_minimum_required(VERSION 3.10.2)

project(mar-compiler VERSION 0.1)

add_executable(${PROJECT_NAME}
  src/main.cpp)

# TODO Move warnings into separate script file.
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

configure_file(config.h.in config.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE include ${PROJECT_BINARY_DIR})

add_subdirectory(tclap)
target_link_libraries(${PROJECT_NAME} tclap)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
