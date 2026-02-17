cmake_minimum_required(VERSION 3.14)

project(test CXX C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_executable(test main/main.cpp)

target_link_libraries(test PUBLIC liban_core.a glfw3dll.lib)