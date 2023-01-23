cmake_minimum_required(VERSION 3.2)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE Debug)
project(LOGGER)

set (PROJECT_DIR ${CMAKE_SOURCE_DIR})

set (PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set (PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/Logger.cpp
    ${PROJECT_SOURCE_DIR}/JsonParser.cpp
    ${PROJECT_SOURCE_DIR}/CurrentPath.cpp)

set(PROJECT_HEADERS
    ${PROJECT_INCLUDE_DIR}/Logger.hpp
    ${PROJECT_INCLUDE_DIR}/JsonParser.hpp
    ${PROJECT_INCLUDE_DIR}/CurrentPath.hpp
    ${PROJECT_INCLUDE_DIR}/LogFrequency.hpp
    ${PROJECT_INCLUDE_DIR}/Colors.h
    ${PROJECT_INCLUDE_DIR}/json.hpp
    ${PROJECT_INCLUDE_DIR}/nlohmann/*.hpp)

    include_directories(${PROJECT_INCLUDE_DIR})

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})