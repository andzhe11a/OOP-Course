#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket {
public:
    GroupTicket(const char* playName, double originalPrice)
        : Ticket(playName, originalPrice * 0.8) {}

    void print() const override {
        std::cout << "Group Ticket - ";
        Ticket::print();
    }
};
