/**
 * @file user.h
 * @brief User Class will inherit from borrowables class
 */
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
protected:
    std::string userName;
    int userID;

public:
    User(std::string userName, int userID)
        : userName(userName), userID(userID) {}

    virtual ~User() = default; 

    
    virtual void displayUserInfo() const {
        std::cout << "User Name: " << userName << std::endl;
        std::cout << "User ID: " << userID << std::endl;
    }
};

#endif // USER_H