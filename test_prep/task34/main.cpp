#include <iostream>
#include "Variable.h"

int main() {
    Variable v1("x", 20);
    Variable v2("x", 20);
    Variable v3("z", 10);

    std::cout << "Variables: " << std::endl;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;

    std::cout << "\nOperator *: " << std::endl;
    std::cout << *v1 << std::endl;

    std::cout << "\nOperator =: " << std::endl;
    v3 = v1; //gets only the value
    std::cout << v3 << std::endl;

    std::cout << std::boolalpha;
    std::cout << "\nIs v1 equal to v2? " << (v1 == v2) << std::endl;
    std::cout << "Is v1 different from v3? " << (v1 != v3) << std::endl;

    return 0;
}
