#include "Account.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>



Account::Account(std::string_view accNumber, int pin, double initialBalance) 
    : accNumber(accNumber), pinHash(hashPin(pin)), balance(initialBalance), 
      is_locked(false), failedAttempts(0) {
    loadTransactionsFromFile(); 
}

std::string Account::hashPin(int pin) const {
    std::ostringstream oss;
    oss << pin;
    std::string pinStr = oss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, pinStr.c_str(), pinStr.size());
    SHA256_Final(hash, &sha256);

    std::ostringstream hashStream;
    hashStream << std::hex << std::setfill('0');
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashStream << std::setw(2) << static_cast<int>(hash[i]);
    }
    return hashStream.str();
}

void Account::saveTransactionToFile(const Transaction& tx) const {
    std::string filePath = "../transactions/" + accNumber + "_transactions.txt";
    /**
     * ios::app
     * Append mode. All output to that file to be appended to the end.
     */
    std::ofstream file(filePath, std::ios::app);
    if (file.is_open()) {
        file << tx.type << "," << tx.amount << "," << tx.timeStamp << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open transaction file for account :" << accNumber << "\n";
    }
}

void Account::loadTransactionsFromFile() {
    std::string filePath = "../transactions/" + accNumber + "_transactions.txt";
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, amountStr, timeStamp;
            if (std::getline(iss, type, ',') && 
                std::getline(iss, amountStr, ',') && 
                std::getline(iss, timeStamp)) {
                //convert string into double                    
                double amount = std::stod(amountStr);
                transaction.emplace_back(type, amount);
                transaction.back().timeStamp = timeStamp;
            }
        }
        file.close();
    }
}

bool Account::authenticate(int pinNumber) {
    if (is_locked) {
        std::cout << "Account " << accNumber << " is locked due to too many failed attempts.\n";
        return false;
    }

    std::string inputPinHash = hashPin(pinNumber);
    if (inputPinHash == pinHash) {
        failedAttempts = 0;
        return true;
    } else {
        failedAttempts++;
        std::cout << "Authentication Failed. Attempt " << failedAttempts << " of " << MAX_ATTEMPTS << "\n";
        if (failedAttempts >= MAX_ATTEMPTS) {
            lock();
            std::cout << "Account " << accNumber << " locked due to too many failed attempts.\n";
        }
        return false;
    }
}

bool Account::deposit(double amount) {
    if (amount >= 0) {
        balance += amount;
        Transaction tx("Deposit", amount);
        transaction.emplace_back(tx);
        saveTransactionToFile(tx); 
        std::cout << "Deposit Successful. New Balance: " << balance << " $\n";
        return true;
    } else {
        return false;
    }
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient Balance\n";
        return false;
    }
    balance -= amount;
    Transaction tx("Withdraw", amount);
    transaction.emplace_back(tx);
    saveTransactionToFile(tx); 
    std::cout << "Withdraw Successful. New Balance: " << balance << " $\n";
    return true;
}

void Account::showTransactionHistory() const {
    std::cout << "Transaction History for Account " << accNumber << ":\n";
    for (const auto& tx : transaction) {
        std::cout << tx.type << " of " << tx.amount << " $ on " << tx.timeStamp << "\n";
    }
}

void Account::sortTransactionByAmount() {
    std::sort(transaction.begin(), transaction.end(), 
              [](const Transaction& a, const Transaction& b) {
                  return a.amount < b.amount;
              });
    std::cout << "Transactions Sorted Ascending By Amount\n";
}

void Account::displayBalance() const {
    std::cout << "Current Balance: " << balance << " $\n";
}

std::string Account::getAccNumber() const { return accNumber; }

bool Account::isLocked() const
{
    return is_locked;
}
void Account::lock()
{
    is_locked = true;
}
void Account::unlock()
{
    is_locked = false;
    failedAttempts = 0;
}