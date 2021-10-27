#include <iostream>
#include <ctime>
#include "ProgramerStatus.hpp"
#include "ProgramerShow.hpp"
#include "LogSystem.hpp"

int main()
{
    time_t now = time(0);
    char * dt = ctime(&now);
    std::cout << dt << std::endl;

    LogSystem::getInstance()->print_log(LOG_INFO);
    
    std::cout << dt << std::endl;
    return 0;
}