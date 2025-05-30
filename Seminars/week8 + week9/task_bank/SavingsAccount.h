#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    SavingsAccount();
    SavingsAccount(double balance, double interestRate);

    double getInterestRate() const;

    void setInterestRate(double rate);

    void applyInterest();
private:
    double interestRate;
};
