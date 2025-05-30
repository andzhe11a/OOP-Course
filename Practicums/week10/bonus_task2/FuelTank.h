#pragma once

class FuelTank {
public:
    FuelTank(double capacity);

    double getCapacity() const;
    double getFuelLevel() const;

    void consume(double liters);
    void refuel(double liters);

private:
    double capacity = 0.0;
    double fuelLevel = 0.0;
};
