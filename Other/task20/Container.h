#pragma once
#include <iostream>

template <typename T>
class Container {
public:
    virtual ~Container() noexcept {};

    virtual bool member(const T& element) const = 0;
    virtual bool add(const T& element) = 0;
    virtual bool remove(const T& element) = 0;
    virtual int getSize() const = 0;
    virtual T& operator[](int i) = 0;

    virtual Container<T>* clone() const = 0;

    friend void printContainer(Container<int>& container) {
        for (int i = 0; i < container.getSize(); i++) {
            std::cout << container[i] << " ";
        }
        std::cout << std::endl;
    }
};
