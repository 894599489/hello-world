cmake_minimum_required(VERSION 3.2)

project(src)

add_subdirectory(test)

file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/leetcode*)
foreach(child ${children})
    if (IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${child} )
        add_subdirectory(${child})
    endif()
endforeach()