#include "book.h"

Book::Book() : BookName(""), BookAuthor(""), bookID(0), isBorrowed(false) {}

Book::Book(std::string BookName, std::string BookAuthor, int bookID)
    : BookName(BookName), BookAuthor(BookAuthor), bookID(bookID), isBorrowed(false) {}

Book::~Book() {}

void Book::displayBookInfo() const {
    std::cout << "Book Name: " << BookName << std::endl;
    std::cout << "Book Author: " << BookAuthor << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Book Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}

bool Book::checkBorrowed() const {
    return isBorrowed;
}

void Book::borrowBook() {
    isBorrowed = true;
}

void Book::returnBook() {
    isBorrowed = false;
}

void Book::borrowItem() {
    borrowBook();
}

void Book::returnItem() {
    returnBook();
}

bool Book::operator==(const Book& other) const {
    return (BookName == other.BookName) &&
           (BookAuthor == other.BookAuthor) &&
           (bookID == other.bookID);
}