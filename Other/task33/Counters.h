#pragma once
#include <iostream>

template <typename T>
class Counters {
public:
    Counters() : readCount(0), changeCount(0) {}

    Counters(const T& val) : value(val), readCount(0), changeCount(0) {}

    const T& getValue() const {
        const_cast<Counters<T>*>(this)->readCount++; // const_cast, to make the counter const
        return value;
    }

    void setValue(const T& newValue) {
        value = newValue;
        changeCount++;
    }

    size_t getReadCount() const {
        return readCount;
    }

    size_t getChangeCount() const {
        return changeCount;
    }

    Counters<T>& operator+=(const Counters<T>& other) {
        if (value == other.value) {
            readCount += other.readCount;
            changeCount += other.changeCount;
        }
        return *this;
    }

private:
    T value;
    size_t readCount = 0;
    size_t changeCount = 0;
};
