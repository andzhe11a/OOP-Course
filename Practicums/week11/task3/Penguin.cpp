#include "Penguin.h"
#include <fstream>

Penguin::Penguin()
    : Prize(49.99, 50) {}

void Penguin::visualize() const {
    std::ifstream file("penguin.txt");
    if (!file.is_open()) {
        std::cerr << "Error: could not open penguin.txt\n";
        return;
    }

    char buffer[256];
    while (file.getline(buffer, sizeof(buffer))) {
        std::cout << buffer << '\n';
    }

    file.close();
}
