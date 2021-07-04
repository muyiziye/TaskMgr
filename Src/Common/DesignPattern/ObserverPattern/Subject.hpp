#ifndef __SUBJECT_HPP__
#define __SUBJECT_HPP__

#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "Observer.hpp"

class Subject
{
public:
    void registerMonitor(std::shared_ptr<ObserverInterface>& test);
    void removeMonitor(std::shared_ptr<ObserverInterface>& test);

protected:
    void notifyMonitor();

private:
    std::vector<std::shared_ptr<ObserverInterface> > m_observerList;
    std::mutex m_mutex;
};

#endif //__SUBJECT_HPP__
