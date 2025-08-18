#include "FuelTank.h"

#include <stdexcept>

FuelTank::FuelTank(double capacity)
    : capacity(capacity), fuelLevel(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Invalid fuel capacity!");
    }
}

double FuelTank::getCapacity() const {
    return capacity;
}

double FuelTank::getFuelLevel() const {
    return fuelLevel;
}

void FuelTank::consume(double liters) {
    if (liters < 0) {
        throw std::invalid_argument("Invalid fuel quantity!");
    }

    if (liters > fuelLevel) {
        throw std::invalid_argument("Not enough fuel!");
    }

    fuelLevel -= liters;
}

void FuelTank::refuel(double liters) {
    if (liters < 0) {
        throw std::invalid_argument("Invalid fuel quantity!");
    }

    fuelLevel += liters;
    if (fuelLevel > capacity) {
        fuelLevel = capacity;
    }
}
