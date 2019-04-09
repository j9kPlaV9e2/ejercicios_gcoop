cmake_minimum_required(VERSION 3.0)

project(ejercicio)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(APP_SOURCES codigo_completo.cpp)

add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME})
