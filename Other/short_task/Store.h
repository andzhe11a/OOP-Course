#pragma once
#include "Phone.h"

class Store {
public:
    Store(double initialBudget);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store() noexcept;

    bool addPhone(const Phone& phoneToAdd);
    bool removePhone(const char* model, const char* brand);
    void printStatus() const;

    void sellCheapestSamsung();

    void swap(Store& other) noexcept;

private:
    double initialBudget = 0.0;
    double currentBudget = 0.0;

    Phone** phones = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void freeDynSt();
    void copyDynSt(const Store& other);
    void resize();

    void removeAt(size_t index);
};
