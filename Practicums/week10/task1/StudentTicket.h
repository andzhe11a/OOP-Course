#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket {
public:
    StudentTicket(const char* playName, double originalPrice)
        : Ticket(playName, originalPrice / 2.0) {}

    void print() const override {
        std::cout << "Student Ticket - ";
        Ticket::print();
    }
};
