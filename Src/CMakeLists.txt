project(main)

add_subdirectory(${main_SOURCE_DIR}/Function/ProgramerStatus)


add_executable(main test.cpp)


target_link_libraries(main ProgramerStatus ProgramerShow)