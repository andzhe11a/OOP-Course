#include "Library1.h"

Library::Library() : Library(8) {}

Library::Library(unsigned capacity) {
    if(capacity == 0) {
        throw std::invalid_argument("bad capacity");
    }
    books = new Book[capacity];
}

Library::Library(const Library& other)
: size(other.size), capacity(other.capacity) {
    copyDynamic(other);
}

Library::~Library() noexcept {
    freeDynamic();
}

void Library::addBook(const Book& book) {
    if(size == capacity) {
        resize();
    }
    books[size++] = book;
}

void Library::addBook(const char* title, unsigned pageCount) {
    if(size == capacity) {
        resize();
    }
    books[size] = Book(title, pageCount);
    size++;
}

void Library::removeBook(const char* name) {
    if(name == nullptr || name[0] == '\0')
        throw std::invalid_argument("bad name");

    for(int i = 0; i < size; i++) {
        if(strcmp(books[i].getTitle(), name) == 0) {
            std::swap(books[i], books[--size]);
            return;
        }
    }
    throw std::logic_error("book not found");
}

unsigned Library::getMedianPages() const {
    unsigned count = 0;

    for(int i = 0; i < size; i++) {
        count += books[i].getPages();
    }

    return count / size;
}

void Library::sortByTitle() {
    for(int i = 0; i < size; i++) {
        int index = i;
        for(int j = i + 1; j < size; j++) {
            if(books[j] < books[index]) {
                index = j;
            }
        }
        if (index != i) {
            std::swap(books[i], books[index]);
        }
    }
}

void Library::freeDynamic() {
    delete[] books;
    books = nullptr;
}

void Library::copyDynamic(const Library& other) {
    books = new Book[other.capacity];

    for(int i = 0; i < other.size; i++) {
        books[i] = other.books[i];
    }
}

const Book& Library::operator[](int index) const {
    return books[index];
}
Book& Library::operator[](int index) {
    return books[index];
}
