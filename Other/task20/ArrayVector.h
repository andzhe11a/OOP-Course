#pragma once
#include <stdexcept>
#include "Container.h"

template <typename T>
class ArrayVector : public Container<T> {
public:
    ArrayVector(size_t cap = 10) : size(0), capacity(cap) {
        arr = new T[capacity];
    }

    ArrayVector(const ArrayVector& other) {
        copyDyn(other);
    }

    ArrayVector& operator=(const ArrayVector& other) {
        if (this != &other) {
            freeDyn();
            copyDyn(other);
        }
        return *this;
    }
    ~ArrayVector() noexcept override {
        freeDyn();
    }

    bool member(const T& element) const override {
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool add(const T& element) override {
        if (size >= capacity) {
            return false;
        }
        arr[size++] = element;
        return true;
    }

    bool remove(const T& element) override {
        for (size_t i = 0; i < size; ++i) {
            if (arr[i] == element) {
                for (size_t j = i; j < size - 1; ++j) {
                    arr[j] = arr[j + 1];
                }
                --size;
                return true;
            }
        }
        return false;
    }

    int getSize() const override {
        return size;
    }

    T& operator[](int i) override {
        if (i < 0 || i >= size)
            throw std::invalid_argument("Invalid index");
        return arr[i];
    }

    Container<T>* clone() const override {
        return new ArrayVector<T>(*this);
    }

private:
    T* arr = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void copyDyn(const ArrayVector& other) {
        arr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
        size = other.size;
        capacity = other.capacity;
    }

    void freeDyn() {
        delete[] arr;

        arr = nullptr;
        size = 0;
        capacity = 0;
    }
};
