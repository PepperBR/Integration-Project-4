cmake_minimum_required(VERSION 3.16)

project(client_test)

add_executable(${PROJECT_NAME})

find_package(Catch2 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Catch2::Catch2WithMain
        grpc_lib
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test_client.cpp
        # ${CMAKE_CURRENT_SOURCE_DIR}/src/test_catalog.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        grpc_lib
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/generated
)