#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
    : BankAccount(), interestRate(1) {}

SavingsAccount::SavingsAccount(double balance, double interestRate)
    : BankAccount(balance), interestRate(interestRate) {}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

void SavingsAccount::setInterestRate(double rate) {
    interestRate = rate;
}

void SavingsAccount::applyInterest() {
    double interest = getBalance() * (interestRate / 100.0);
    deposit(interest);
}
