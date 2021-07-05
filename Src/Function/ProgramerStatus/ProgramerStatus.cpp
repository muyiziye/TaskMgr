#include <iostream>

#include "ProgramerStatus.hpp"

static ProgramerStatus *m_programer_status = NULL;
static std::mutex m_programer_status_mutex;

ProgramerStatus::ProgramerStatus(){}

ProgramerStatus::~ProgramerStatus(){}

ProgramerStatus* ProgramerStatus::getInstance()
{
    if (NULL == m_programer_status)
    {
        std::lock_guard<std::mutex> lck (m_programer_status_mutex);
        if (NULL == m_programer_status)
        {
            m_programer_status = new ProgramerStatus();
        }
    }
    return m_programer_status;
}

void ProgramerStatus::programerStatusChange()
{
    notifyMonitor();
    return;    
}


