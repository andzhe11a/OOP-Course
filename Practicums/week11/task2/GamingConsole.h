#pragma once
#include "Computer.h"

class GamingConsole : public Computer {
public:
    GamingConsole(double cpuPower, const char* videoCardModel, unsigned powerSupply, unsigned ram)
        : Computer(cpuPower, videoCardModel, powerSupply, ram) {}

    void print() const override {
        std::cout << "Type of computer: Gaming Console\n";
    }

    void peripherals() const override {
        const char* devices[] = { "Joystick", "Monitor" };
        const int deviceCount = 2;

        std::cout << "Peripherals: ";
        for (int i = 0; i < deviceCount; i++) {
            std::cout << devices[i] << " ";
        }
        std::cout << "\n";
    }
};
