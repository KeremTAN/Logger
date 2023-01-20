cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)
project(LOGGER)

set (PROJECT_DIR ${CMAKE_SOURCE_DIR})

set (PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set (PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/logger.cpp)

set(PROJECT_HEADERS
    ${PROJECT_INCLUDE_DIR}/logger.hpp
    ${PROJECT_INCLUDE_DIR}/json.hpp)

    include_directories(${PROJECT_INCLUDE_DIR})

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})