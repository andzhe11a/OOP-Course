#pragma once
#include "Book1.h"

class Library {
public:
    Library();
    Library(unsigned capacity);
    Library(const Library& other);
    Library& operator=(const Library& other);
    ~Library() noexcept;

    void addBook(const char* name, unsigned pageCount);
    void addBook(const Book& book);
    void removeBook(const char* name);
    unsigned getMedianPages() const;

    size_t getSize() const;
    size_t getCapacity() const;

    void sortByTitle();

    const Book& operator[](int index) const;
    Book& operator[](int index);

private:
    Book* books = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void resize();
    void freeDynamic();
    void copyDynamic(const Library& other);
};
