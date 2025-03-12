#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <string_view>
#include <vector>
#include <fstream>
#include "Transaction.hpp"
#include <openssl/sha.h>

class Account {
private:
    std::string accNumber;
    std::string pinHash ;
    int pin;
    double balance;
    std::vector<Transaction> transaction;
    bool is_locked ;
    int failedAttempts ;
    static const int MAX_ATTEMPTS = 3 ;

    std::string hashPin(int pin) const;
    void saveTransactionToFile(const Transaction& tx) const; 
    void loadTransactionsFromFile();                         

public:
    Account(std::string_view accNumber, int pin, double initialBalance);

    bool authenticate(int pinNumber);
    bool deposit(double amount);
    bool withdraw(double amount);
    void showTransactionHistory() const;
    void sortTransactionByAmount();
    void displayBalance() const;

    std::string getAccNumber() const;

    bool isLocked() const ;
    void lock() ;
    void unlock();
};

#endif // ACCOUNT_HPP