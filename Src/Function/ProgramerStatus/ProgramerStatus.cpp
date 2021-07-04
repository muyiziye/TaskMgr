#include <iostream>

#include "ProgramerStatus.hpp"

ProgramerStatus::ProgramerStatus(){}

ProgramerStatus::~ProgramerStatus(){}

void ProgramerStatus::programerStatusChange()
{
    notifyMonitor();
    return;    
}


