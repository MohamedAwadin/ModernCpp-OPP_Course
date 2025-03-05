#include "teacher.h"
#include <iostream>
#include <string>



Teacher::Teacher(std::string TeacherName, int TeacherID) : User(TeacherName, TeacherID)
{
    
}

void Teacher::displayUserInfo() const
{
    std::cout << "Teacher Name : " << userName << std::endl;
    std::cout << "Teacher ID : " << userID << std::endl;
}