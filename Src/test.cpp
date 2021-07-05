#include <iostream>
#include <ctime>
#include <ProgramerStatus.hpp>
#include <ProgramerShow.hpp>

int main()
{
    std::cout << "test" << std::endl;

    time_t now = time(0);
    char * dt = ctime(&now);
    std::cout << dt << std::endl;
    
    std::shared_ptr<ObserverInterface> show_1(new ProgramerShow());
    ProgramerStatus::getInstance()->registerMonitor(show_1);

    std::shared_ptr<ObserverInterface> show_2(new ProgramerShow("test_name"));
    ProgramerStatus::getInstance()->registerMonitor(show_2);

    ProgramerStatus::getInstance()->programerStatusChange();


    ProgramerStatus::getInstance()->removeMonitor(show_1);
    ProgramerStatus::getInstance()->removeMonitor(show_2);
    
    std::cout << dt << std::endl;
    return 0;
}