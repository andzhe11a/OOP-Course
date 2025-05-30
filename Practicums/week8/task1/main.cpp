#include <iostream>
#include "MyString.h"

int main() {
    MyString s("Example");

    std::cout << "Initial string: " << s.c_str() << "\n";
    std::cout << "Size: " << s.size() << "\n";
    std::cout << "Capacity: " << s.capacity() << "\n";

    std::cout << "Character at index 2: " << s.at(2) << "\n";

    std::cout << "First character: " << s.front() << "\n";
    std::cout << "Last character: " << s.back() << "\n";

    std::cout << "Is empty? " << (s.empty() ? "Yes" : "No") << "\n";

    MyString s2("Example");
    MyString s3("Different");
    std::cout << "Equals s2? " << (s.equals(s2) ? "Yes" : "No") << "\n";
    std::cout << "Equals s3? " << (s.equals(s3) ? "Yes" : "No") << "\n";

    s.clear();
    std::cout << "After clear(): " << s.c_str() << "\n";

    return 0;
}
