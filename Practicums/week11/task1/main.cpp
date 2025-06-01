#include <iostream>
#include "Vehicle.h"
#include "Bicycle.h"
#include "Car.h"

int main() {
    Vehicle v1("Red", "Toyota", 2015, 5, 180);
    std::cout << "Vehicle:\n" << v1 << "\n\n";

    Bicycle bike("Blue", "Cross", 2021, 1, 30, 21, true, true);
    std::cout << "Bicycle:\n" << bike << "\n\n";

    Car car("Black", "BMW", "M3", 2023, 5, 240, 4, 420);
    std::cout << "Car:\n" << car << "\n\n";

    return 0;
}
