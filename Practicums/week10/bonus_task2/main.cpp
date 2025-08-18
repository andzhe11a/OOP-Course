#include <iostream>
#include "Engine.h"
#include "Tire.h"
#include "Battery.h"
#include "Car.h"

int main() {
    Engine engine("BMW", "something", 400);
    Tire tire("Michelin", "something", 225, 55, 17);
    Battery battery("Energy", "something", 60, "1234");

    std::cout << engine << std::endl;
    std::cout << tire << std::endl;
    std::cout << battery << std::endl;

    Car car(engine, tire, tire, tire, tire, battery, 1500, 50);

    std::cout << "\n--- Start of journey ---\n";
    std::cout << "Fuel level in tank: " << car.getTank().getFuelLevel() << " L\n";
    std::cout << "Mileage: " << car.getMileage() << " km\n";

    std::cout << "\n--- 20 km journey ---\n";
    car.drive(20);

    std::cout << "Fuel level in tank: " << car.getTank().getFuelLevel() << " L\n";
    std::cout << "Mileage: " << car.getMileage() << " km\n";

    std::cout << "\n--- 25 km journey ---\n";
    car.drive(25);

    std::cout << "Fuel level in tank: " << car.getTank().getFuelLevel() << " L\n";
    std::cout << "Mileage: " << car.getMileage() << " km\n";

    std::cout << "\n--- 100 km journey (failed attempt) ---\n";
    car.drive(100);

    std::cout << "Fuel level in tank: " << car.getTank().getFuelLevel() << " L\n";
    std::cout << "Mileage: " << car.getMileage() << " km\n";

    return 0;
}
