#pragma once
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector() : data(nullptr), size(0), capacity(0) {}

    MyVector(const MyVector& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~MyVector() {
        delete[] data;
    }

    void pushBack(const T& value) {
        if (size >= capacity)
            resize(capacity == 0 ? 2 : capacity * 2);
        data[size++] = value;
    }

    void popBack() {
        if (size == 0)
            throw std::out_of_range("Cannot pop from empty vector.");
        --size;
    }

    void insert(size_t index, const T& value) {
        if (index > size)
            throw std::out_of_range("Index out of range.");

        if (size >= capacity)
            resize(capacity == 0 ? 2 : capacity * 2);

        for (size_t i = size; i > index; --i)
            data[i] = data[i - 1];

        data[index] = value;
        ++size;
    }

    void remove(size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range.");

        for (size_t i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        --size;
    }

    size_t count() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T& back() {
        if (isEmpty())
            throw std::out_of_range("Vector is empty.");
        return data[size - 1];
    }

    T& operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range.");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range.");
        return data[index];
    }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
};

template<typename T>
void printVector(const MyVector<T>& vec) {
    for (size_t i = 0; i < vec.count(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}
