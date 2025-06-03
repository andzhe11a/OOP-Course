#include <iostream>
#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"

int main() {
    PC myPC(3, "something", 500, 8);
    Laptop myLaptop(2, "something", 450, 4);
    GamingConsole myConsole(4, "something", 500, 16);

    std::cout << "--- PC ---\n";
    myPC.print();
    myPC.peripherals();
    std::cout << "CPU Power: " << myPC.getCpuPower() << "\n";
    std::cout << "Video Card Model: " << myPC.getVideoCardModel() << "\n";
    std::cout << "Power Supply: " << myPC.getPowerSupply() << "\n";
    std::cout << "RAM: " << myPC.getRam() << "\n\n";

    std::cout << "--- Laptop ---\n";
    myLaptop.print();
    myLaptop.peripherals();
    std::cout << "CPU Power: " << myLaptop.getCpuPower() << "\n";
    std::cout << "Video Card Model: " << myLaptop.getVideoCardModel() << "\n";
    std::cout << "Power Supply: " << myLaptop.getPowerSupply() << " \n";
    std::cout << "RAM: " << myLaptop.getRam() << "\n\n";

    std::cout << "--- Gaming Console ---\n";
    myConsole.print();
    myConsole.peripherals();
    std::cout << "CPU Power: " << myConsole.getCpuPower() << "\n";
    std::cout << "Video Card: " << myConsole.getVideoCardModel() << "\n";
    std::cout << "Power Supply: " << myConsole.getPowerSupply() << " \n";
    std::cout << "RAM: " << myConsole.getRam() << "\n";

    return 0;
}
