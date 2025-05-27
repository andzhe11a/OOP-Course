#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount()
    : BankAccount(), overdraftLimit(0) {}

CheckingAccount::CheckingAccount(double balance, double overdraftLimit)
    : BankAccount(balance), overdraftLimit(overdraftLimit) {}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}

void CheckingAccount::setOverdraftLimit(double limit) {
    overdraftLimit = limit;
}

double CheckingAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Cannot withdraw a negative amount.\n";
        return 0;
    }

    double availableFunds = getBalance() + overdraftLimit;

    if (amount > availableFunds) {
        std::cout << "Insufficient funds including overdraft limit.\n";
        return 0;
    }

    balance -= amount;
    BankAccount::totalBankBalance -= amount;
    return amount;
}
