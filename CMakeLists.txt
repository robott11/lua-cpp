cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

set(APP_NAME lua-cpp)
set(SRC_DIR src)
set(
    SOURCES 
    ${SRC_DIR}/main.cpp
)

project(${APP_NAME})

add_executable(${APP_NAME} ${SOURCES})

target_link_libraries(${APP_NAME} lua)