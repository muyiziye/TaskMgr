project(TaskMrg)

cmake_minimum_required(VERSION 3.10)

include_directories(
    ${TaskMrg_SOURCE_DIR}/Src/Common/DesignPattern/ObserverPattern/
    ${TaskMrg_SOURCE_DIR}/Src/Function/ProgramerStatus/
)

add_definitions("-Wall -lpthread -g -Werror")

set(install_dir ${TaskMrg_SOURCE_DIR}/Bin/)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH "\${ORIGIN}")

add_subdirectory(${TaskMrg_SOURCE_DIR}/Src/)
