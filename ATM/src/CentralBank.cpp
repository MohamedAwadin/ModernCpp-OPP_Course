#include "CentralBank.hpp"
#include <iostream>

void CentralBank::addAccount(std::string_view accNumber, int pin, double initialBalance) {
    accounts.emplace_back(std::make_shared<Account>(accNumber, pin, initialBalance));
}

std::shared_ptr<Account> CentralBank::authenticate(std::string_view accNumber, int pinNum) {
    for (const auto& acc : accounts) {
        if (acc->getAccNumber() == accNumber) {
            if (acc->authenticate(pinNum)) {
                return acc; 
            }
            return nullptr; 
        }
    }
    return nullptr; 
}