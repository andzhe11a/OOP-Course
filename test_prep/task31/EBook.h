#pragma once
#include "Book1.h"

class EBook : public Book {
public:
    EBook();
    EBook(const char* name, unsigned pages, unsigned byteSize, unsigned opens);

    void setByteSize(unsigned size);
    void setOpens(unsigned count);

    unsigned getByteSize() const;
    unsigned getOpens() const;

    unsigned getRating() const;

private:
    unsigned byteSize = 0;
    unsigned opens = 0;
};
