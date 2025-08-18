#include "CarPart.h"
#include <cstring>

unsigned CarPart::nextId = 1;

void CarPart::copyDyn(const CarPart& other) {
    manufacturer = new char[strlen(other.manufacturer) + 1];
    strcpy(manufacturer, other.manufacturer);

    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

void CarPart::freeDyn() {
    delete[] manufacturer;
    delete[] description;
    manufacturer = nullptr;
    description = nullptr;
}

CarPart::CarPart() : id(nextId++), manufacturer(nullptr), description(nullptr) {}

CarPart::CarPart(const char* manufacturer, const char* description)
    : id(nextId++) {
    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

CarPart::CarPart(const CarPart& other)
    : id(nextId++) {
    copyDyn(other);
}

CarPart &CarPart::operator=(const CarPart &other) {
    if (this != &other) {
        CarPart temp(other);
        std::swap(manufacturer, temp.manufacturer);
        std::swap(description, temp.description);
    }
    return *this;
}

CarPart::~CarPart() noexcept {
    freeDyn();
}

unsigned CarPart::getId() const {
    return id;
}

const char* CarPart::getManufacturer() const {
    return manufacturer;
}

const char* CarPart::getDescription() const {
    return description;
}

void CarPart::print(std::ostream& os) const {
    os << "(" << id << ") by " << manufacturer << " – " << description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& part) {
    part.print(os);
    return os;
}
