#include "Car.h"

Car::Car(const Engine& engine,
         const Tire& tire1,
         const Tire& tire2,
         const Tire& tire3,
         const Tire& tire4,
         const Battery& battery,
         double weight,
         double tankCapacity)
    : engine(engine), tires{tire1, tire2, tire3, tire4}, battery(battery), weight(weight), tank(tankCapacity) {
    tires[0] = tire1;
    tires[1] = tire2;
    tires[2] = tire3;
    tires[3] = tire4;
}

const FuelTank& Car::getTank() const {
    return tank;
}

void Car::drive(double km) {
    double neededFuel = km * 1.00;
    double currentFuel = tank.getFuelLevel();

    if (currentFuel >= neededFuel) {
        tank.consume(neededFuel);
        mileage += km;
    } else {
        throw std::runtime_error("Not enough fuel for this journey!");
    }
}

double Car::getMileage() const {
    return mileage;
}

double Car::getWeight() const {
    return weight;
}
