#include <iostream>
#include <cstring>
#include "Smartphone.h"

void Smartphone::copyDynS(const Smartphone& other) {
    os = new char[strlen(other.os) + 1];
    strcpy(os, other.os);
}

void Smartphone::freeDynS() {
    delete[] os;
}

Smartphone::Smartphone(const char* model, const char* brand, double price, const char* os, unsigned memory)
    : Phone(model, brand, price), memory(memory) {
    this->os = new char[strlen(os) + 1];
    strcpy(this->os, os);
}

Smartphone::Smartphone(const Smartphone& other)
    : Phone(other), memory(other.memory) {
    copyDynS(other);
}

void Smartphone::swap(Smartphone& other) noexcept {
    Phone::swap(other);
    
    using std::swap;
    swap(os, other.os);
    swap(memory, other.memory);
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        Smartphone temp(other);
        swap(temp);
    }
    return *this;
}

Smartphone::~Smartphone() noexcept {
    freeDynS();
}

double Smartphone::getPrice() const {
    return Phone::getPrice() + memory;
}

void Smartphone::print() const {
    Phone::print();

    std::cout << " OS: " << os << ", Memory: " << memory << " GB" << std::endl;
}

Phone* Smartphone::clone() const {
    return new Smartphone(*this);
}
