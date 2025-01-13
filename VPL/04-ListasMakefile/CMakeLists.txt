cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "vpl_execution")
set(PROJECT_C "${PROJECT_NAME}c")

project("${PROJECT_NAME}" VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR "src")
file(GLOB SRC_FILES "${SRC_DIR}/CPP/*.cpp")
file(GLOB SRC_FILES_C "${SRC_DIR}/C/*.c")

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_executable("${PROJECT_C}" "${SRC_FILES_C}")
target_include_directories("${PROJECT_C}" PRIVATE include/C)

target_include_directories(${PROJECT_NAME} PRIVATE include/CPP)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
  # target_compile_options("${PROJECT_NAME}" PRIVATE -fpack-struct=0)
  target_compile_options("${PROJECT_C}" PRIVATE -fpack-struct=1)
endif()

add_custom_target(
  run
  COMMAND ${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
