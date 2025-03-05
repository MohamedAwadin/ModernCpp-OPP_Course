//Library Managment System 

#include <iostream>
#include "includes/library.h"
#include "includes/student.h"
#include "includes/teacher.h"
#include "includes/book.h"


int main()
{
    Library library;
    library.addBook(Book("C++", "Mohamed Awadin", 123));
    library.addBook(Book("Python", "Anas ", 88));
    library.addBook(Book("Java", "Kareem", 878));

    library.addUser(new Student("Mohamed", 1));
    library.addUser(new Student("Ahmed", 2));
    library.addUser(new Teacher("Fady", 3));

    library.displayBooks();
    library.displayUsers();

    return 0;


}




