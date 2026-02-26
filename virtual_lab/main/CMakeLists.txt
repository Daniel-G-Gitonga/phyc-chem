project(Wc_Labs)


add_executable(Wc_Labs main.cpp)
target_include_directories(Wc_Labs 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_SOURCE_DIR}/core/includes ${CMAKE_SOURCE_DIR}/labs/chemical_lab/includes
    )
target_link_directories(Wc_Labs 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs
    PUBLIC ${CMAKE_SOURCE_DIR}/build/main   # for dlls
    )



target_link_libraries(Wc_Labs

    PUBLIC chemistry_v1
    PUBLIC opengl32
  

    )