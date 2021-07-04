project(ProgramerStatus)

include_directories(
    ${ProgramerStatus_SOURCE_DIR}
    ${TaskMrg_SOURCE_DIR}/Src/Common/DesignPattern/ObserverPattern/
)

set(ProgramerStatus_src ProgramerStatus.cpp)
set(ProgramerShow_src ProgramerShow.cpp)

add_library(ProgramerStatus SHARED ${ProgramerStatus_src})

add_library(ProgramerShow SHARED ${ProgramerShow_src})