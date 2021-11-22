project(main)

include_directories(
    ${TaskMrg_SOURCE_DIR}/Src/Common/DesignPattern/ObserverPattern/
    ${TaskMrg_SOURCE_DIR}/extlibs/include
)

add_subdirectory(${main_SOURCE_DIR}/Function/ProgramerStatus)

find_library(LOGSYSTEM_PATH logsystem ${TaskMrg_SOURCE_DIR}/extlibs/lib)

message(${TaskMrg_SOURCE_DIR}/extlibs/lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}  ProgramerStatus ProgramerShow 
    ${LOGSYSTEM_PATH}
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${install_dir}
)
