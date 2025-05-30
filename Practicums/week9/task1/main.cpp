#include "Complex.h"

int main() {
    Complex a(2, 3);
    Complex b(1, -4);

    std::cout << "a = " << a << "\nb = " << b << "\n\n";

    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a / b = " << a / b << "\n\n";

    std::cout << "Conjugate of a: " << a.conjugate() << '\n';
    std::cout << "Conjugate of b: " << b.conjugate() << "\n\n";

    std::cout << std::boolalpha;
    std::cout << "a < b: " << (a < b) << '\n';
    std::cout << "a == b: " << (a == b) << "\n\n";

    Complex input;
    std::cout << "Enter a complex number (real and imaginary part): ";
    std::cin >> input;
    std::cout << "You entered: " << input << '\n';

    return 0;
}
