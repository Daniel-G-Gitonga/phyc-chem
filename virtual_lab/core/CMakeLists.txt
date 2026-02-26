project(core)

add_library(core STATIC Application.cpp Shader.cpp  glad.c)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_SOURCE_DIR}/labs/chemical_lab/includes)
target_link_directories(
     core PUBLIC ${CMAKE_SOURCE_DIR}/main/libs
         )
target_link_libraries(core
     PUBLIC glfw3dll.lib
    )  

add_custom_command(
    TARGET core
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E  copy_if_different
    ${CMAKE_SOURCE_DIR}/build/core/libcore.a
    ${CMAKE_SOURCE_DIR}/main/libs
)

