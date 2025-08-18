#include <iostream>
#include <cstring>
#include "Smartphone.h"

void Smartphone::copyDynS(const Smartphone& other) {
    os = new char[strlen(other.os) + 1];
    strcpy(os, other.os);
}

void Smartphone::freeDynS() const {
    delete[] os;
}

Smartphone::Smartphone(const char* model, const char* brand, double price, const char* os, unsigned memory)
    : Phone(model, brand, price), memory(memory) {
    this->os = new char[strlen(os) + 1];
    strcpy(this->os, os);
}

Smartphone::Smartphone(const Smartphone& other)
    : Phone(other) {
    copyDynS(other);
    memory = other.memory;
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        copyDynS(other);
        freeDynS();
        memory = other.memory;
    }
    return *this;
}

Smartphone::~Smartphone() noexcept {
    freeDynS();
}

double Smartphone::getPrice() const {
    return price + memory;
}

void Smartphone::print() const {
    Phone::print();

    std::cout << " OS: " << os << ", Memory: " << memory << " GB" << std::endl;
}

Phone* Smartphone::clone() const {
    return new Smartphone(*this);
}