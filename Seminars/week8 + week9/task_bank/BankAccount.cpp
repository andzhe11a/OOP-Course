#include "BankAccount.h"

int BankAccount::nextAccNumber = 1;
double BankAccount::totalBankBalance = 0;

BankAccount::BankAccount() : accNumber(nextAccNumber++), balance(0) {}

BankAccount::BankAccount(double balance)
    : accNumber(nextAccNumber++), balance(balance) {
    totalBankBalance += balance;
}

int BankAccount::getAccNumber() const {
    return accNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

double BankAccount::getTotalBankBalance() {
    return totalBankBalance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    totalBankBalance += amount;
}

double BankAccount::withdraw(double amount) {
    if (amount < 0) {
        return 0;
    }

    if (balance < amount)
    {
        double leftover = balance;
        balance = 0;

        totalBankBalance -= leftover;
        return leftover;
    }

    balance -= amount;
    totalBankBalance -= amount;

    return amount;
}

BankAccount operator+(BankAccount& lhs, BankAccount& rhs) {
    double leftAmount = lhs.getBalance();
    double rightAmount = rhs.getBalance();

    lhs.withdraw(leftAmount);
    rhs.withdraw(rightAmount);

    return BankAccount(leftAmount + rightAmount);
}

bool operator==(const BankAccount& lhs, const BankAccount& rhs)
{
    return lhs.getAccNumber() == rhs.getAccNumber() && lhs.getBalance() == rhs.getBalance();
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Account number: " << account.getAccNumber() << ", balance: " << account.getBalance() << " (Total balance of the bank: " << BankAccount::getTotalBankBalance() << ")";
    return os;
}
