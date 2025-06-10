#pragma once
#include "Counters.h"

template <typename T>
class CounterArray : public Counters<T> {
public:
    CounterArray(size_t cap = 8) : size(0), capacity(cap) {
        arr = new Counters<T>[capacity];
    }

    CounterArray(const CounterArray& other) {
        copyDyn(other);
    }

    CounterArray& operator=(const CounterArray& other) {
        if (this != &other) {
            freeDyn();
            copyDyn(other);
        }
        return *this;
    }

    ~CounterArray() {
        freeDyn();
    }

    void add(const T& value) {
        if (size >= capacity) {
            resize();
        }

        arr[size++] = Counters<T>(value);
    }

    size_t getSize() const {
        return size;
    }

    const T& operator[](size_t index) {
        return arr[index].getValue();
    }

    void sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < size; ++j)
                if (arr[j].getValue() < arr[minIndex].getValue())
                    minIndex = j;

            if (i != minIndex)
                std::swap(arr[i], arr[minIndex]);
        }

        std::cout << "\nStatistics after sorting:\n";
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Element: " << arr[i].getValue()
                      << " , Read: " << arr[i].getReadCount()
                      << " , Changed: " << arr[i].getChangeCount() << "\n";
        }
    }

    void statistics() const {
        Counters<T>* uniqueStats = new Counters<T>[size];
        size_t uniqueCount = 0;

        for (size_t i = 0; i < size; ++i) {
            bool found = false;

            for (size_t j = 0; j < uniqueCount; ++j) {
                if (uniqueStats[j].getValue() == arr[i].getValue()) {
                    uniqueStats[j] += arr[i];
                    found = true;
                    break;
                }
            }

            if (!found) {
                uniqueStats[uniqueCount] = arr[i];
                ++uniqueCount;
            }
        }

        std::cout << "\nStatistics grouped by value:\n";
        for (size_t i = 0; i < uniqueCount; ++i) {
            std::cout << "Element: " << uniqueStats[i].getValue()
                      << " , Reads: " << uniqueStats[i].getReadCount()
                      << " , Changes: " << uniqueStats[i].getChangeCount()
                      << std::endl;
        }

        delete[] uniqueStats;
    }

private:
    Counters<T>* arr = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void resize() {
        capacity *= 2;
        Counters<T>* newArr = new Counters<T>[capacity];

        for (size_t i = 0; i < size; ++i)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
    }

    void copyDyn(const CounterArray& other) {
        arr = new Counters<T>[other.capacity];
        for (size_t i = 0; i < other.size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    void freeDyn() const {
        delete[] arr;
    }
};
