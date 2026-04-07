cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}Test)

target_include_directories(${PROJECT_NAME}Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(${PROJECT_NAME}Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/teste_Catalogo.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME}Test Project3_lib)
