#include "EBook.h"

EBook::EBook() : Book(), byteSize(0), opens(0) {}

EBook::EBook(const char* name, unsigned pages, unsigned byteSize, unsigned opens)
    : Book(name, pages), byteSize(byteSize), opens(opens) {}

void EBook::setByteSize(unsigned size) {
    byteSize = size;
}

void EBook::setOpens(unsigned count) {
    opens = count;
}

unsigned EBook::getByteSize() const {
    return byteSize;
}

unsigned EBook::getOpens() const {
    return opens;
}

unsigned EBook::getRating() const {
    if (opens > 200)
        return 5;
    return opens / 40;
}
