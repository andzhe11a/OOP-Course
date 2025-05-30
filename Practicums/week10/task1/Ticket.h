#pragma once
#include <iostream>

class Ticket {
public:
    Ticket();
    Ticket(const char* playName, double price);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);
    virtual ~Ticket() noexcept;

    virtual void print() const;
protected:
    char* playName = nullptr;
    double price = 0;

    void copyPlayName(const char* playName);
};
