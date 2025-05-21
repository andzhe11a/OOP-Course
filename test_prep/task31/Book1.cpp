#include "Book1.h"
#include "stdexcept"

Book::Book() : title(nullptr), pages(0) {}

Book::Book(const char* title, unsigned pageCount) {
    setPages(pages);
    setTitle(title);
}

Book::Book(const Book& other) : pages(other.pages) {
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);
}

Book& Book::operator=(const Book& other) {
    if(this != &other) {
        Book temp(other);
        std::swap(title, temp.title);
        std::swap(pages, temp.pages);
    }
    return *this;
}

Book::~Book() noexcept {
    delete[] title;
    title = nullptr;
}

void Book::setTitle(const char* name) {
    if(name == nullptr) {
        throw std::invalid_argument("bad name");
    }

    char* temp = new char[strlen(name) + 1];
    strcpy(temp, name);
    delete[] title;

    title = temp;
}
void Book::setPages(unsigned pageCount) {
    this->pages = pageCount;
}

const char* Book::getTitle() const {
    return title;
}
unsigned Book::getPages() const {
    return pages;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.title << " " << book.pages << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    char buff[1024];
    is.getline(buff, sizeof(buff));
    book.setTitle(buff);
    is >> book.pages;
    is.ignore();

    return is;
}

bool operator<=(const Book& lhs, const Book& rhs) {
    return strcmp(lhs.getTitle(), rhs.getTitle()) <= 0;
}

bool operator>=(const Book& lhs, const Book& rhs) {
    return strcmp(lhs.getTitle(), rhs.getTitle()) >= 0;
}

bool operator<(const Book& lhs, const Book& rhs) {
    return strcmp(lhs.getTitle(), rhs.getTitle()) < 0;
}

bool operator>(const Book& lhs, const Book& rhs) {
    return strcmp(lhs.getTitle(), rhs.getTitle()) > 0;
}