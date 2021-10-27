project(LogSystem)

set(LogSystem_src LogSystem.cpp)

add_library(LogSystem SHARED ${LogSystem_src})

install(TARGETS LogSystem
    LIBRARY DESTINATION ${install_dir}
)