#include <iostream>
#include <cstring>
#include "Phone.h"

void Phone::copyDyn(const Phone& other) {
    try {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);

        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }
    catch (...) {
        freeDyn();
        throw;
    }
}

void Phone::freeDyn() {
    delete[] model;
    delete[] brand;
}

Phone::Phone(const char* model, const char* brand, double price) : price(price) {
    if (price < 0) {
        throw std::invalid_argument("Price cannot be negative.");
    }
    
    try {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);

        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    catch (...) {
        freeDyn();
        throw;
    }
}

Phone::Phone(const Phone& other) : price(other.price) {
    copyDyn(other);
}

void Phone::swap(Phone& other) noexcept {
    using std::swap;
    swap(model, other.model);
    swap(brand, other.brand);
    swap(price, other.price);
}

Phone& Phone::operator=(const Phone& other) {
    if (this != &other) {
        Phone temp(other);
        swap(temp);
    }
    return *this;
}

Phone::~Phone() noexcept {
    freeDyn();
}

const char* Phone::getModel() const {
    return model;
}

const char* Phone::getBrand() const {
    return brand;
}

double Phone::getPrice() const {
    return price;
}

void Phone::print() const {
    std::cout << brand << " " << model << ", Price: " << getPrice() << " lv." << std::endl;
}

Phone* Phone::clone() const {
    return new Phone(*this);
}
