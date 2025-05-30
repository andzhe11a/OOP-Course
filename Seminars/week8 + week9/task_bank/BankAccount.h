#pragma once
#include <iostream>
#include <fstream>

class BankAccount {
public:
  BankAccount();
  BankAccount(double balance);

  int getAccNumber() const;
  double getBalance() const;
  static double getTotalBankBalance();

  void deposit(double amount);
  double withdraw(double amount);

private:
  int accNumber;
  static int nextAccNumber;

protected:
  double balance;
  static double totalBankBalance;
};

BankAccount operator+(BankAccount& lhs, BankAccount& rhs);

bool operator==(const BankAccount& lhs, const BankAccount& rhs);

std::ostream& operator<<(std::ostream& os, const BankAccount& account);
