cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME}Test)

find_package(Catch2 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}Test PRIVATE Catch2::Catch2WithMain)

target_sources(${PROJECT_NAME}Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/teste_Catalogo.cpp)

target_link_libraries(${PROJECT_NAME}Test PRIVATE Project3_lib)
