#ifndef ATM_HPP
#define ATM_HPP

#include "CentralBank.hpp"
#include <string_view>

class ATM : public CentralBank {
public:
    ATM() = default;

    
    std::shared_ptr<Account> authenticate(std::string_view accNumber, int pinNum) override;
};

#endif // ATM_HPP