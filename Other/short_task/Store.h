#pragma once
#include "Phone.h"

class Store {
public:
    Store(double initialBudget);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store() noexcept;

    bool addPhone(Phone* phoneToAdd);
    bool removePhone(const char* model, const char* brand);

    void printStatus() const;

    void sellCheapestSamsung();

private:
    double initialBudget = 0.0;
    double currentBudget = 0.0;

    Phone** phones = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free() const;
    void copy(const Store& other);

    void resize();
};