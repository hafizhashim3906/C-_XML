cmake_minimum_required(VERSION 3.5)

project("carmedialab")

set(CMAKE_CXX_STANDARD 11)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
endif()

include_directories(lib)
include_directories(src/include)

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/Library.xml
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(main
    src/main.cpp
)
