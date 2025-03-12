#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP



#include <string>
#include <string_view>
#include "TimeUtils.hpp" 

class Transaction {
public:
    std::string type;
    double amount;
    std::string timeStamp;

    Transaction(std::string_view type, double amount);
};

#endif // TRANSACTION_HPP