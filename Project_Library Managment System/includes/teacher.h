#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"


class Teacher : public User
{
private:
    /* data */
public:
    Teacher(std::string TeacherName, int TeacherID);
    void displayUserInfo() const override;
};

#endif // TEACHER_H