#include <iostream>
#include "Book.h"
#include "EBook.h"
#include "Library.h"

int main() {
    Library lib;

    lib.addBook("Book1", 218);
    lib.addBook("Book2", 328);
    lib.addBook("Book3", 311);

    std::cout << "Library contents (before sorting):\n";
    for (size_t i = 0; i < lib.getSize(); ++i) {
        std::cout << lib[i];
    }

    lib.sortByTitle();

    std::cout << "\nLibrary contents (after sorting):\n";
    for (size_t i = 0; i < lib.getSize(); ++i) {
        std::cout << lib[i];
    }

    lib.removeBook("Book2");

    std::cout << "\nLibrary contents (after removing '1984'):\n";
    for (size_t i = 0; i < lib.getSize(); ++i) {
        std::cout << lib[i];
    }

    std::cout << "\nAverage page count: " << lib.getMedianPages() << "\n";

    EBook ebook("Clean Code", 464, 1024000, 250);
    std::cout << "\nEBook: " << ebook;
    std::cout << "Rating: " << ebook.getRating() << "\n";

    return 0;
}
