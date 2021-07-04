#ifndef __PROGRAMERSHOW_HPP__
#define __PROGRAMERSHOW_HPP__

#include "Observer.hpp"
#include "Display.hpp"

typedef unsigned int uint;

typedef struct status{
    uint rate;
    uint time;
}rate_time;

class ProgramerShow:public ObserverInterface,public DisplayInterface
{
public:
    ProgramerShow();
    ~ProgramerShow();



    virtual void update();

    virtual void show();

};

#endif // __PROGRAMERSHOW_HPP__