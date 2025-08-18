#include <iostream>
#include "MyVector.h"

int main() {
    MyVector<int> vec;

    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    std::cout << "After pushBack: ";
    printVector(vec);

    vec.popBack();
    std::cout << "After popBack: ";
    printVector(vec);

    vec.insert(1, 15);
    std::cout << "After insert at index 1: ";
    printVector(vec);

    vec.remove(1);
    std::cout << "After remove at index 1: ";
    printVector(vec);

    std::cout << "Count: " << vec.count() << "\n";
    std::cout << "Is empty: " << (vec.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Back element: " << vec.back() << "\n";
    std::cout << "Element at index 0: " << vec[0] << "\n";

    vec.clear();
    std::cout << "After clear, is empty: " << (vec.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
