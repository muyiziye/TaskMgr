#include "Subject.hpp"


void  Subject::registerMonitor(std::shared_ptr<ObserverInterface>& test)
{
    std::lock_guard<std::mutex> lck (m_mutex);
    
    bool find = false;
    auto it = m_observerList.begin();
    for(; it != m_observerList.end(); it++)
    {
        if (*it == test)
        {
            find = true;
            break;
        }
    }
    if (!find)
    {
        m_observerList.push_back(test);
    }

    return;
}

void  Subject::removeMonitor(std::shared_ptr<ObserverInterface>& test)
{
    std::lock_guard<std::mutex> lck (m_mutex);

    auto it = m_observerList.begin();
    for(; it != m_observerList.end(); )
    {
        if (*it == test)
        {
            m_observerList.erase(it);
        }
        else
        {
            it++;
        }
    }

    return;
}

void Subject::notifyMonitor()
{
    std::lock_guard<std::mutex> lck (m_mutex);
    
    auto it = m_observerList.begin();
    for(; it != m_observerList.end(); it++)
    {
        (*it)->update();
    }

    return;
}
