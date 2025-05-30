#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

void printLine() {
    std::cout << "----------------------------------------\n";
}

int main() {
    BankAccount basic(1000);
    SavingsAccount savings(2000, 5.0);
    CheckingAccount checking(1500, 500);

    std::cout << "Initial account states:\n";
    std::cout << "Basic account: " << basic << "\n";
    std::cout << "Savings account: " << savings << "\n";
    std::cout << "Checking account: " << checking << "\n";
    printLine();

    std::cout << "Making deposits:\n";
    basic.deposit(500);
    savings.deposit(1000);
    checking.deposit(750);

    std::cout << "After deposits:\n";
    std::cout << "Basic account: " << basic << "\n";
    std::cout << "Savings account: " << savings << "\n";
    std::cout << "Checking account: " << checking << "\n";
    printLine();

    std::cout << "Testing withdrawals:\n";
    double withdrawn1 = basic.withdraw(300);
    double withdrawn2 = savings.withdraw(500);
    checking.withdraw(2000);

    std::cout << "After withdrawals (withdrew $" << withdrawn1 << " from basic, $" << withdrawn2 << " from savings):\n";
    std::cout << "Basic account: " << basic << "\n";
    std::cout << "Savings account: " << savings << "\n";
    std::cout << "Checking account: " << checking << "\n";
    printLine();

    std::cout << "Applying interest to savings account:\n";
    std::cout << "Before interest: " << savings << "\n";
    savings.applyInterest();
    std::cout << "After interest: " << savings << "\n";
    printLine();

    std::cout << "Testing checking account overdraft limit:\n";
    std::cout << "Overdraft limit: $" << checking.getOverdraftLimit() << "\n";
    checking.withdraw(1000);
    std::cout << "After withdrawal within overdraft limit: " << checking << "\n";
    checking.withdraw(5000);
    std::cout << "After attempted withdrawal exceeding limit: " << checking << "\n";
    printLine();

    BankAccount account1(100);
    BankAccount account2(100);
    std::cout << "Testing account comparison:\n";
    std::cout << "Are accounts equal? " << (account1 == account2 ? "Yes" : "No") << "\n";

    BankAccount sumAccount = account1 + account2;
    std::cout << "Sum of accounts: " << sumAccount << "\n";
    printLine();

    return 0;
}
