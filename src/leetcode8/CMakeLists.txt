cmake_minimum_required(VERSION 3.2)

get_filename_component(prjname ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)

project(${prjname})

aux_source_directory(. SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH ${MY_BIN_DIR})