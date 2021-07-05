#ifndef __LOG_SYSTEM_HPP__
#define __LOG_SYSTEM_HPP__

#include <iostream>
#include <mutex>

typedef struct{
    bool save_to_file;
    bool save_to_terminal;
}LOG_SAVED_TARGET;

enum LOG_LEVEL{ 
    LOG_ERR = 0,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG
};

class LogSystem
{
// 共有成员函数
public:
    // 获取单利模式日志系统的实例
    static LogSystem* getInstance();

    /* 初始化日志系统
     * [in] log_level,     初始化日志的级别
     * [in] log_saved_tgt, 初始化日志保存的目标
     * [in] log_file_name, 初始化日志文件的名称
     * [in] log_max_size,  初始化日志文件的最大存储空间
    */
    void init(LOG_LEVEL log_level, LOG_SAVED_TARGET log_saved_tgt,
                std::string log_file_name, unsigned int log_max_size);

    ~LogSystem();


// 私有成员函数
private:
    LogSystem();

// 私有成员变量
private:
    LOG_LEVEL           m_log_level;        // 记录日志的级别
    LOG_SAVED_TARGET    m_log_saved_tgt;    // 记录日志保存的位置
    std::string         m_log_file_name;    // 记录日志存放的文件
    unsigned int        m_log_max_size;     // 记录日志文件最大空间占用，单位(M)
    static std::mutex   m_instance_mutex;   // 保护日志实例为单利的信号量
    std::mutex          m_write_log_mutex;  // 保护日志记录的信号量
};

#endif // !__LOG_SYSTEM_HPP__