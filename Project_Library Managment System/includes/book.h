#ifndef BOOK_H
#define BOOK_H

#include "borrowables.h"
#include <string>
#include <iostream>

class Book : public borrowables {
private:
    std::string BookName;
    std::string BookAuthor;
    int bookID;
    bool isBorrowed;

public:
    Book();
    Book(std::string BookName, std::string BookAuthor, int bookID);
    ~Book();

    void displayBookInfo() const;
    bool checkBorrowed() const;
    void borrowBook();
    void returnBook();

    // Implement pure virtual functions
    void borrowItem() override;
    void returnItem() override;

    // Add operator==
    bool operator==(const Book& other) const;
};

#endif // BOOK_H