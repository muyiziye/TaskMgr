#ifndef __PROGRAMERSTATUS_HPP__
#define __PROGRAMERSTATUS_HPP__

#include "Subject.cpp"

class ProgramerStatus:public Subject
{
public:
    ProgramerStatus();
    ~ProgramerStatus();

//private:
    void programerStatusChange();

};

#endif // __PROGRAMERSTATUS_HPP__