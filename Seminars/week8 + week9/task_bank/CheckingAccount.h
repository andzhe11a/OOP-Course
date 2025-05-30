#pragma once
#include "BankAccount.h"

class CheckingAccount : public BankAccount{
public:
    CheckingAccount();
    CheckingAccount(double balance, double overdraftLimit);

    double getOverdraftLimit() const;

    void setOverdraftLimit(double limit);

    double withdraw(double amount);
private:
    double overdraftLimit;
};
