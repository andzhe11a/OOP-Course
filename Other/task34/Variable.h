#pragma once
#include "Named.h"

class Variable : public Named<int> {
public:
    Variable(const char* name = "", int value = 0) : Named<int>(name, value) {}

    int operator*() const {
        return getValue();
    }

    Variable& operator=(const Variable& other) {
        if (this != &other) {
            setValue(other.getValue()); //only value, not name
        }
        return *this;
    }

    bool operator==(const Variable& other) {
        return std::strcmp(getName(), other.getName()) == 0
                && getValue() == other.getValue();
    }

    bool operator!=(const Variable& other) {
        return !(*this == other);
    }
};
