#pragma once
#include <fstream>

class Book {
public:
    Book();
    Book(const char* title, unsigned pages);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book() noexcept;

    void setTitle(const char* name);
    void setPages(unsigned pages);

    const char* getTitle() const;
    unsigned getPages() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);

private:
    char* title = nullptr;
    unsigned pages = 0;
};

bool operator<=(const Book& lhs, const Book& rhs);
bool operator>=(const Book& lhs, const Book& rhs);
bool operator<(const Book& lhs, const Book& rhs);
bool operator>(const Book& lhs, const Book& rhs);
