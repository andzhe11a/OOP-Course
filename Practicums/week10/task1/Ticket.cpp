#include "Ticket.h"

void Ticket::copyPlayName(const char* name) {
    playName = new char[strlen(name) + 1];
    strcpy(playName, name);
}

Ticket::Ticket() : playName(nullptr), price(0) {}

Ticket::Ticket(const char *playName, double price)
    :price(price) {
    copyPlayName(playName);
}

Ticket::Ticket(const Ticket& other) {
    copyPlayName(other.playName);
}

Ticket &Ticket::operator=(const Ticket &other) {
    if (this != &other) {
        Ticket temp(other);
        std::swap(playName, temp.playName);
        std::swap(price, temp.price);
    }
    return *this;
}

Ticket::~Ticket() noexcept {
    delete[] playName;
}

void Ticket::print() const {
    std::cout << "Play: " << playName << "\nPrice: " << price << " levs\n";
}
