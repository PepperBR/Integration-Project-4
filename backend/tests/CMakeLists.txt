cmake_minimum_required(VERSION 3.16)

project(tests)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_executable(${PROJECT_NAME})

find_package(Catch2 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Catch2::Catch2WithMain
        backend_lib            
        proto-objects
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test_catalog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test_meter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test_phaseMeter.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        backend_lib
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/../include
        ${CMAKE_SOURCE_DIR}/../../generated
)