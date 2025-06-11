#include <iostream>
#include "CounterArray.h"

int main() {
    CounterArray<int> arr;

    arr.add(3);
    arr.add(1);
    arr.add(4);
    arr.add(1);
    arr.add(5);
    arr.add(9);
    arr.add(2);
    arr.add(6);

    std::cout << "Reading elements:\n";
    for (size_t i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.sort();

    arr.statistics();

    return 0;
}
