project(an_main)

include_directories(${CMAKE_SOURCE_DIR}/core/includes)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)
add_executable(an_main main.cpp)
target_link_libraries(an_main PUBLIC liban_core.a glfw3dll.lib)