/**
 * @file library.cpp
 * @brief Library Class will inherit from Book class
 */

#include "library.h"
#include <iostream>
#include "user.h"
#include <vector>
#include <algorithm>


Library::Library()
{
    std::cout << "Library Constructor Called" << std::endl;
}

void Library::addBook(const Book& book)
{
    
    
    books.push_back(book);
}

void Library::addUser(User* user)
{
    users.push_back(user);
}

void Library::displayBooks() const
{
    std::cout << "Books in Library : " << std::endl;
    /**
     * @brief Display All Books in Library
     * Important of 'const' keyword in the function
     * 1. It tells the compiler that the function will not modify the object
     */
    for (const auto& book : books)
    {
        book.displayBookInfo();
    }
}

void Library::displayUsers() const
{
    for (const auto& user : users)
    {
        user->displayUserInfo();
    }
}

void Library::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        delete *it;  
        users.erase(it);  
    }
}

void Library::removeBook(Book* book) {
    auto it = std::find(books.begin(), books.end(), *book);
    if (it != books.end()) {
        books.erase(it);  
    }
}

Library::~Library() {
    std::cout << "Library Destructor Called" << std::endl;
    for (auto& user : users) {
        delete user;
    }
}

