#ifndef CENTRAL_BANK_HPP
#define CENTRAL_BANK_HPP

#include <vector>
#include <memory>
#include <string_view>
#include "Account.hpp"

class CentralBank {
protected:
    std::vector<std::shared_ptr<Account>> accounts; 

public:
    CentralBank() = default;
    virtual ~CentralBank() = default; 

    void addAccount(std::string_view accNumber, int pin, double initialBalance);
    virtual std::shared_ptr<Account> authenticate(std::string_view accNumber, int pinNum); 
};

#endif // CENTRAL_BANK_HPP