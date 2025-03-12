#include "Transaction.hpp"

Transaction::Transaction(std::string_view type, double amount) 
    : type(type), amount(amount), timeStamp(getCurrentTime()) {}