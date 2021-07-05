#ifndef __PROGRAMERSTATUS_HPP__
#define __PROGRAMERSTATUS_HPP__

#include "Subject.cpp"
#include <mutex>

class ProgramerStatus:public Subject
{


public:
    static ProgramerStatus* getInstance();
    ~ProgramerStatus();

    void programerStatusChange();


private:
    ProgramerStatus();

};

#endif // __PROGRAMERSTATUS_HPP__