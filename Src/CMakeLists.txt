project(main)

include_directories(
    ${TaskMrg_SOURCE_DIR}/Src/Common/DesignPattern/ObserverPattern/
    ${TaskMrg_SOURCE_DIR}/Src/Common/LogSystem/
)

add_subdirectory(${main_SOURCE_DIR}/Function/ProgramerStatus)
add_subdirectory(${main_SOURCE_DIR}/Common/LogSystem)


add_executable(main main.cpp)


target_link_libraries(main ProgramerStatus ProgramerShow LogSystem)


install(TARGETS main
    RUNTIME DESTINATION ${install_dir}
)