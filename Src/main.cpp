#include <iostream>
#include <ctime>
#include "ProgramerStatus.hpp"
#include "ProgramerShow.hpp"
#include "logSystem.hpp"

int main()
{
    time_t now = time(0);
    char * dt = ctime(&now);
	LOG_ERR("Just show the %d log\n", *dt);

    return 0;
}
