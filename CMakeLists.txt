project(TaskMrg)

include_directories(
    ${TaskMrg_SOURCE_DIR}/Src/Common/DesignPattern/ObserverPattern/
    ${TaskMrg_SOURCE_DIR}/Src/Function/ProgramerStatus/
)

add_definitions("-Wall -lpthread -g -Werror")

message("=============="${TaskMrg_SOURCE_DIR})

add_subdirectory(${TaskMrg_SOURCE_DIR}/Src/)

# install()