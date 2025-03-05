/**
 * @file library.h
 * @brief Library Class will inherit from Book class
 */

#ifndef LIBRARY_H
#define LIBRARY_H


#include "book.h"
#include <iostream>
#include "user.h"
#include <vector>

class Library 
{
private:
    /**
     * @brief Add Book to Library
     * 
     */
    std::vector<Book> books; // Composition : Library has a collection of Books >> You can't find Library without Books
    /**
     * @brief Add User to Library
     * @def: User can be Student or Teacher
     * @
     */
    std::vector<User*> users; // Aggregation : Library has a collection of Users  >> You can find Users outside the Library
public:
    Library(/* args */);
    ~Library();

    /**
     * @brief Add Book to Library
     * 
     */
    void addBook(const Book& book);
    /**
     * @brief Add User to Library
     * 
     */
    void addUser(User* user);
    /**
     * @brief Display All Books in Library
     * 
     */
    void displayBooks() const;
    /**
     * @brief Display All Users in Library
     * 
     */
    void displayUsers() const;

    /**
     * @brief Remove User from Library
     * 
     */
    void removeUser(User* user);
    /**
     * @brief Remove Book from Library
     * 
     */
    void removeBook(Book* book);
    
    

};

#endif // LIBRARY_H