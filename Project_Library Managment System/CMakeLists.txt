cmake_minimum_required(VERSION 3.10)
project(Modern_CPP_Project)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(includes)


set(SOURCES
    src/book.cpp
    src/library.cpp
    src/student.cpp
    src/teacher.cpp
    main.cpp
)


add_executable(Modern_CPP_Project ${SOURCES})
