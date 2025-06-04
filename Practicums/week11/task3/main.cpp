#include "Penguin.h"

int main() {
    Penguin reward;

    std::cout << "Price: " << reward.getPrice() << "\n";
    std::cout << "Points required: " << reward.getPoints() << "\n";
    std::cout << "Visualizing prize:\n";
    reward.visualize();

    return 0;
}
