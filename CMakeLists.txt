cmake_minimum_required(VERSION 3.10)
project(LongArithmetic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_compile_options(-O2 -Wall)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/LongArithmetic.cpp ${CMAKE_CURRENT_SOURCE_DIR}/LongArithmetic.hpp)

add_library(LongArithmetic SHARED ${SOURCES})
add_executable(main main.cpp)
target_link_libraries(main LongArithmetic)

add_executable(Tests Tests.cpp)
target_link_libraries(Tests LongArithmetic)