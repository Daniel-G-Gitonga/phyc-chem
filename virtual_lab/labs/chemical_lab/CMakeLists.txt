project(chemistry_v1)


add_library(chemistry_v1 STATIC chemical_lab.cpp)

target_include_directories(chemistry_v1 
     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_CURRENT_SOURCE_DIR}/../../core/includes
     )


add_custom_command(
    TARGET chemistry_v1
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/build/labs/chemical_lab/libchemistry_v1.a
    ${CMAKE_SOURCE_DIR}/build/main
)


target_link_directories(
    chemistry_v1
    PUBLIC ${CMAKE_SOURCE_DIR}/main/libs
)

target_link_libraries(
    chemistry_v1
    PUBLIC core
)