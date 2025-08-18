#include "Vehicle.h"
#include <cstring>

void Vehicle::copyDyn(const Vehicle& other) {
    color = new char[strlen(other.color) + 1];
    std::strcpy(color, other.color);

    brand = new char[strlen(other.brand) + 1];
    std::strcpy(brand, other.brand);
}

void Vehicle::freeDyn() {
    delete[] color;
    delete[] brand;

    color = nullptr;
    brand = nullptr;
}

Vehicle::Vehicle() : color(nullptr), brand(nullptr), year(0), seatCount(0), maxSpeed(0) {}

Vehicle::Vehicle(const char* color, const char* brand, unsigned year, unsigned seatCount, unsigned maxSpeed)
    : year(year), seatCount(seatCount), maxSpeed(maxSpeed) {
    this->color = new char[strlen(color) + 1];
    std::strcpy(this->color, color);

    this->brand = new char[strlen(brand) + 1];
    std::strcpy(this->brand, brand);
}

Vehicle::Vehicle(const Vehicle& other) {
    copyDyn(other);

    year = other.year;
    seatCount = other.seatCount;
    maxSpeed = other.maxSpeed;
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        Vehicle temp(other);
        std::swap(color, temp.color);
        std::swap(brand, temp.brand);
        std::swap(year, temp.year);
        std::swap(seatCount, temp.seatCount);
        std::swap(maxSpeed, temp.maxSpeed);
    }
    return *this;
}

Vehicle::~Vehicle() noexcept {
    freeDyn();
}

const char* Vehicle::getColor() const {
    return color;
}

const char* Vehicle::getBrand() const {
    return brand;
}

unsigned Vehicle::getYear() const {
    return year;
}

unsigned Vehicle::getSeatCount() const {
    return seatCount;
}

unsigned Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << "Brand: " << vehicle.brand
       << ", Color: " << vehicle.color
       << ", Year: " << vehicle.year
       << ", Seats: " << vehicle.seatCount
       << ", Max Speed: " << vehicle.maxSpeed << " km/h";
    return os;
}
