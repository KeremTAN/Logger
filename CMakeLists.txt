cmake_minimum_required(VERSION 3.2)

project(LOGGER)

set (PROJECT_DIR ${CMAKE_SOURCE_DIR})

set (PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set (PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/logger.cpp
    ${PROJECT_SOURCE_DIR}/jsoncpp.cpp)

set(PROJECT_HEADERS
    ${PROJECT_INCLUDE_DIR}/logger.hpp
    ${PROJECT_INCLUDE_DIR}/json.h
    ${PROJECT_INCLUDE_DIR}/json_features.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/json.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/allocator.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/assertions.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/config.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/forwards.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/json_features.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/reader.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/value.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/version.h
    ${PROJECT_INCLUDE_DIR}/jsoncpp/json/writer.h)

    include_directories(${PROJECT_INCLUDE_DIR})

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})