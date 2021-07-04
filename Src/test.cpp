#include <iostream>
#include <ctime>
#include <ProgramerStatus.hpp>
#include <ProgramerShow.hpp>

int main()
{

    std::cout << "test" << std::endl;

    // 创建唯一监视器，监视所有的任务的状态
    ProgramerStatus ps;


    time_t now = time(0);
    char * dt = ctime(&now);
    std::cout << dt << std::endl;
    
    
    std::shared_ptr<ObserverInterface> show_1(new ProgramerShow());
    ps.registerMonitor(show_1);

    ps.programerStatusChange();

    ps.removeMonitor(show_1);
    
    std::cout << dt << std::endl;
    return 0;
}