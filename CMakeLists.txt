cmake_minimum_required(VERSION 2.8)

project(Logger)

set (PROJECT_DIR ${CMAKE_SOURCE_DIR})

set (PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set (PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/logger.cpp)

    set(PROJECT_HEADERS
    ${PROJECT_INCLUDE_DIR}/logger.hpp
    ${PROJECT_INCLUDE_DIR}/json/json.h
    ${PROJECT_INCLUDE_DIR}/json/allocator.h
    ${PROJECT_INCLUDE_DIR}/json/assertions.h
    ${PROJECT_INCLUDE_DIR}/json/config.h
    ${PROJECT_INCLUDE_DIR}/json/forwards.h
    ${PROJECT_INCLUDE_DIR}/json/json_features.h
    ${PROJECT_INCLUDE_DIR}/json/reader.h
    ${PROJECT_INCLUDE_DIR}/json/value.h
    ${PROJECT_INCLUDE_DIR}/json/version.h
    ${PROJECT_INCLUDE_DIR}/json/writer.h
    )

    include_directories(${PROJECT_INCLUDE_DIR})

    link_libraries(
        ${PROJECT_DIR}/lib/libjsoncpp.dylib
        ${PROJECT_DIR}/lib/libjsoncpp.25.dylib
    )

    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})