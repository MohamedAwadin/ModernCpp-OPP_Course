cmake_minimum_required(VERSION 3.10)
project(ATM_System VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(SOURCES
    main.cpp
    src/Account.cpp
    src/ATM.cpp
    src/TimeUtils.cpp
    src/Transaction.cpp
    src/CentralBank.cpp
)
find_package(OpenSSL REQUIRED)
add_executable(atm ${SOURCES})
target_include_directories(atm PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(atm PRIVATE OpenSSL::SSL OpenSSL::Crypto)


