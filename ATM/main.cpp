#include "ATM.hpp"
#include <iostream>

int main() {
    ATM atm;

    // Add an account
    atm.addAccount("12346", 1111, 1000.0);
    atm.addAccount("12556", 1111, 1000.0);
    atm.addAccount("12546", 1111, 1000.0);
    atm.addAccount("1234s", 1111, 1000.0);

    
    auto account1 = atm.authenticate("12346", 1111);
    if (account1) {
        account1->displayBalance();
        account1->deposit(500.0);
        account1->withdraw(200.0);
        account1->sortTransactionByAmount();
        account1->showTransactionHistory();
    }


    auto account2 = atm.authenticate("12556", 1111);
    if (account2) {
        account2->displayBalance();
        account2->deposit(500.0);
        account2->withdraw(200.0);
        account2->sortTransactionByAmount();
        account2->showTransactionHistory();
    }

    auto account3 = atm.authenticate("12546", 1111);
    if (account3) {
        account3->displayBalance();
        account3->deposit(500.0);
        account3->withdraw(200.0);
        account3->sortTransactionByAmount();
        account3->showTransactionHistory();
    }
    
    auto invalidAccount1 = atm.authenticate("1234s", 9999);
    if (!invalidAccount1) {
        std::cout << "Access denied.\n";
    }

    auto invalidAccount2 = atm.authenticate("12555", 1111);
    if (!invalidAccount2) {
        std::cout << "Access denied.\n";
    }
    std::cout << "\nTesting failed attempts:\n";
    atm.authenticate("12346", 9999); 
    atm.authenticate("12346", 9999); 
    atm.authenticate("12346", 9999); 
    atm.authenticate("12346", 1111); 
    return 0;
}