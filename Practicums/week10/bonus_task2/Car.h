#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tire.h"
#include "Battery.h"

class Car {
public:
    Car(const Engine& engine,
        const Tire& tire1,
        const Tire& tire2,
        const Tire& tire3,
        const Tire& tire4,
        const Battery& battery,
        double weight,
        double tankCapacity);

    const FuelTank& getTank() const;

    double getMileage() const;
    double getWeight() const;

    void drive(double km);

private:
    FuelTank tank;
    Engine engine;
    Tire tires[4];
    Battery battery;

    double mileage = 0;
    double weight;
};
