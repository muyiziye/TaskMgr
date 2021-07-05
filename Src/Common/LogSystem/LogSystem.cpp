#include "LogSystem.hpp"

LogSystem*   m_log_instance = NULL;

LogSystem* LogSystem::getInstance()
{
    if (NULL == m_log_instance)
    {
        std::lock_guard<std::mutex> lck (m_instance_mutex);
        if (NULL == m_log_instance)
        {
            m_log_instance = new LogSystem();
        }
    }

    return m_log_instance;
}

void LogSystem::init(LOG_LEVEL log_level, LOG_SAVED_TARGET log_saved_tgt,
        std::string log_file_name, unsigned int log_max_size)
{
    m_log_level     = log_level;
    m_log_saved_tgt = log_saved_tgt;
    m_log_file_name = log_file_name;
    m_log_max_size  = log_max_size;
    return;
}

LogSystem::LogSystem(/* args */)
{
}


LogSystem::~LogSystem()
{

}
