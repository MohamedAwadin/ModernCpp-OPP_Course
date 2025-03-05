#include "student.h"
#include <iostream>
#include <string>

Student::Student(std::string StudentName, int StudentID) : User(StudentName, StudentID)
{

}

void Student::displayUserInfo() const
{
    std::cout << "Student Name : " <<userName << std::endl;
    std::cout << "Student ID : " << userID << std::endl;
}

