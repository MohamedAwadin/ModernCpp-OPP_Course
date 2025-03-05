/**
 * @file student.h
 * @brief Student Class will inherit from User class
 */
#ifndef STUDENT_H
#define STUDENT_H
 #include "user.h"
#include <iostream>
#include <string>


class Student : public User
{
   
   public: 
    Student(std::string StudentName, int StudentID);
    void displayUserInfo() const override;

};

#endif // STUDENT_H