#include <iostream>
#include "Container.h"
#include "ArrayVector.h"
#include "Set.h"

int main() {
    std::cout << "Testing ArrayVector:\n";
    ArrayVector<int> vector(5);

    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(2);
    vector.add(4);
    
    printContainer(vector);

    std::cout << "Removing 2: " << (vector.remove(2) ? "success" : "failed") << std::endl;
    std::cout << "Vector after removing 2: " << std::endl;
    printContainer(vector);


    std::cout << "\nTesting Set:\n";
    Set<int> set(new ArrayVector<int>(5));

    set.add(1);
    set.add(2);
    set.add(3);
    set.add(2);
    set.add(4);
    
    printContainer(set);

    std::cout << "Is 2 in set? " << (set.member(2) ? "yes" : "no") << std::endl;
    std::cout << "Is 5 in set? " << (set.member(5) ? "yes" : "no") << std::endl;

    std::cout << "Removing 3: " << (set.remove(3) ? "success" : "failed") << std::endl;
    std::cout << "Set after removing 3: " << std::endl;
    printContainer(set);
    
    return 0;
}
