cmake_minimum_required(VERSION 3.10)
project(MyDatabase C)

set(CMAKE_C_STANDARD 99)

# Define project source directory
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Include directories for headers
include_directories(${SRC_DIR})

# Add source files manually for better organization
set(SOURCES
    ${SRC_DIR}/main.c
    ${SRC_DIR}/repl/shell.c
    ${SRC_DIR}/storage/pager.c
    ${SRC_DIR}/table/table.c
    ${SRC_DIR}/util/utils.c
)

# Define executable
add_executable(MyDatabase ${SOURCES})
