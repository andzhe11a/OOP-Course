#include <iostream>
#include "Store.h"
#include "Phone.h"
#include "Smartphone.h"

int main() {
    std::cout << "Creating a store with initial budget of 10000 lv.: " << std::endl;
    Store myStore(10000);
    myStore.printStatus();

    std::cout << "\nAdding new phones: " << std::endl;
    myStore.addPhone(new Smartphone("Galaxy S5", "Samsung", 1800, "Android 15", 256));
    myStore.addPhone(new Smartphone("Galaxy A5", "Samsung", 800, "Android 15", 128));
    myStore.addPhone(new Smartphone("15", "Apple", 9500, "iOS 15", 256));

    myStore.printStatus();

    std::cout << "\nRemoving the cheapest Samsung phone in the store: " << std::endl;
    myStore.sellCheapestSamsung();

    myStore.printStatus();

    return 0;
}