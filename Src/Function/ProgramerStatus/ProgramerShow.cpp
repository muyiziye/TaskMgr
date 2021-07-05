#include <iostream>

#include "ProgramerShow.hpp"

ProgramerShow::ProgramerShow()
    :m_programe_name("Default_name")
{}
ProgramerShow::ProgramerShow(std::string programe_name)
    :m_programe_name(programe_name)
{}

ProgramerShow::~ProgramerShow(){}

void ProgramerShow::update()
{
    std::cout << "Enter ProgramerShow::update" << std::endl;
    std::cout << "This name is " << m_programe_name << "." << std::endl;
    std::cout << "Exit ProgramerShow::update" << std::endl;
    return;    
}


void ProgramerShow::show()
{
    std::cout << "Enter ProgramerShow::show" << std::endl;

    std::cout << "Exit ProgramerShow::show" << std::endl;
    return;
}