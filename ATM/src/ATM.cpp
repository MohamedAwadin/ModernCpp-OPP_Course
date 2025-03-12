#include "ATM.hpp"
#include <iostream>

std::shared_ptr<Account> ATM::authenticate(std::string_view accNumber, int pinNum) {
    std::shared_ptr<Account> acc = CentralBank::authenticate(accNumber, pinNum);
    if (acc) {
        std::cout << "Authentication Successful\n";
    } else {
        std::cout << "Authentication Failed\n";
    }
    return acc;
}