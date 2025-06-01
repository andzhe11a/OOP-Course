#include "Car.h"
#include <cstring>

void Car::copyDyn(const Car& other) {
    model = new char[strlen(other.model) + 1];
    std::strcpy(model, other.model);
}

void Car::freeDyn() {
    delete[] model;

    model = nullptr;
}

Car::Car() = default;

Car::Car(const char* color, const char* brand, const char* model, unsigned year,
         unsigned seatCount, unsigned maxSpeed, unsigned doorCount, unsigned horsePower)
    : Vehicle(color, brand, year, seatCount, maxSpeed),
      doorCount(doorCount), horsePower(horsePower) {
    this->model = new char[strlen(model) + 1];
    std::strcpy(this->model, model);
}

Car::Car(const Car& other) : Vehicle(other) {
    copyDyn(other);

    doorCount = other.doorCount;
    horsePower = other.horsePower;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Car temp(other);
        std::swap(model, temp.model);
        std::swap(doorCount, temp.doorCount);
        std::swap(horsePower, temp.horsePower);
    }
    return *this;
}

Car::~Car() noexcept {
    freeDyn();
}

const char* Car::getModel() const {
    return model;
}

unsigned Car::getDoorCount() const {
    return doorCount;
}

unsigned Car::getHorsePower() const {
    return horsePower;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << static_cast<const Vehicle&>(car) << "\n"
       << "Model: " << car.model << "\n"
       << "Doors: " << car.doorCount << "\n"
       << "Horsepower: " << car.horsePower << " hp";
    return os;
}
