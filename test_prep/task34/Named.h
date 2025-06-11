#pragma once
#include <iostream>

template <typename T>
class Named {
public:
    Named() : name(nullptr), value() {}

    Named(const char* name, const T& value) : value(value) {
        setName(name);
    }

    Named(const Named& other) {
        copyDyn(other);
    }

    Named& operator=(const Named& other) {
        if (this != &other) {
            freeDyn();
            copyDyn(other);
        }
        return *this;
    }

    ~Named() {
        freeDyn();
    }

    const char* getName() const {
        return name;
    }

    const T& getValue() const {
        return value;
    }

    void setName(const char* newName) {
        if(newName == nullptr) {
            throw std::invalid_argument("bad name");
        }

        char* temp = new char[std::strlen(newName) + 1];
        std::strcpy(temp, newName);
        delete[] name;
        name = temp;
    }

    void setValue(const T& newValue) {
        value = newValue;
    }

    friend std::ostream& operator<<(std::ostream& os, const Named<T>& obj) {
        os << obj.name << ":" << obj.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Named<T>& obj) {
        char buff[1024];
        is.getline(buff, sizeof(buff));
        obj.setName(buff);

        is >> obj.value;
        is.ignore();

        return is;
    }

private:
    char* name = nullptr;
    T value = 0;

    void copyDyn(const Named& other) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);

        value = other.value;
    }

    void freeDyn() {
        delete[] name;
        name = nullptr;
    }
};
