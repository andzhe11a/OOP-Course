#include <iostream>
#include <cstring>
#include "Phone.h"

void Phone::copyDyn(const Phone& other) {
    model = new char[strlen(other.model) + 1];
    strcpy(model, other.model);

    brand = new char[strlen(other.brand) + 1];
    strcpy(brand, other.brand);
}

void Phone::freeDyn() const {
    delete[] model;
    delete[] brand;
}

Phone::Phone(const char* model, const char* brand, double price) : price(price) {
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);

    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

Phone::Phone(const Phone& other) {
    copyDyn(other);
    price = other.price;
}

Phone& Phone::operator=(const Phone& other) {
    if (this != &other) {
        freeDyn();
        copyDyn(other);
        price = other.price;
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