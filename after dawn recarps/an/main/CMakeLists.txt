project(an_main)

include_directories(${CMAKE_SOURCE_DIR}/core/includes ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_SOURCE_DIR}/core/backend/includes ${CMAKE_SOURCE_DIR}/core/imgui/includes)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)
find_package(OPENGL)
message("package")

add_executable(an_main main.cpp Application.cpp )
target_link_libraries(an_main PUBLIC liban_core.a glfw3dll.lib)