#pragma once
#include "Computer.h"

class Laptop : public Computer {
public:
    Laptop(double cpuPower, const char* videoCardModel, unsigned powerSupply, unsigned ram)
        : Computer(cpuPower, videoCardModel, powerSupply, ram) {}

    void print() const override {
        std::cout << "Type of computer: Laptop\n";
    }

    void peripherals() const override {
        const char* devices[] = { "Mouse Pad", "Keyboard", "Monitor" };
        const int deviceCount = 3;

        std::cout << "Peripherals: ";
        for (int i = 0; i < deviceCount; i++) {
            std::cout << devices[i] << " ";
        }
        std::cout << "\n";
    }
};
