#include "LogSystem.hpp"

#include <string.h> 

#include <iostream>

LogSystem*   m_log_instance = NULL;
static std::mutex   m_instance_mutex;   // 保护日志实例为单利的信号量

#define LOG(log_level) do{          \
    if (log_level > m_log_level)    \
    {                               \
        LogSystem::getInstance()->print_log(LOG_INFO);                            \
    }                               \
}while(0);                          

#define FILENAME(x) strrchr(x,'/')?strrchr(x,'/')+1:x

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


void LogSystem::print_log(LOG_LEVEL log_level)
{
    std::ofstream output("debug.log");
    my_stream tee(std::cout, output);
    tee << "Test" << "[" << std::string(FILENAME(__FILE__)) << ":" << __LINE__ << "]:" << __FUNCTION__ << std::endl;
    
}

int my_buf::overflow(int c)
{
    if (EOF == c)
    {
        return !EOF;
    }
    else
    {
        int const r1 = buf1->sputc(c);
        int const r2 = buf2->sputc(c);
        return r1 == EOF || r2 == EOF ? EOF : c;
    }
}

int my_buf::sync()
{
    int const r1 = buf1->pubsync();
    int const r2 = buf2->pubsync();
    return r1 == 0 && r2 == 0 ? 0 : -1;
}

my_stream::my_stream(std::ostream& out1, std::ostream& out2)
    :std::ostream(&buf),
    buf(out1.rdbuf(), out2.rdbuf())
{}
 