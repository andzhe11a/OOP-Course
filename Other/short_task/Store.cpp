#include <iostream>
#include <cstring>
#include "Store.h"
#include "Phone.h"

void Store::copyDynSt(const Store& other) {
    phones = new Phone*[other.capacity];

    for (size_t i = 0; i < other.size; ++i) {
        phones[i] = other.phones[i]->clone();
    }
}

void Store::freeDynSt() {
    for (size_t i = 0; i < size; ++i) {
        delete phones[i];
    }
    delete[] phones;
}

void Store::resize() {
    capacity *= 2;
    Phone** newPhones = new Phone*[capacity];

    for (size_t i = 0; i < size; ++i) {
        newPhones[i] = phones[i];
    }

    delete[] phones;
    phones = newPhones;
}

Store::Store(double initialBudget)
    : initialBudget(initialBudget),
      currentBudget(initialBudget),
      size(0),
      capacity(8)
{
    phones = new Phone*[capacity];
}

Store::Store(const Store& other)
    : initialBudget(other.initialBudget), 
      currentBudget(other.currentBudget),
      size(other.size),
      capacity(other.capacity)
{
    copyDynSt(other);
}

void Store::swap(Store& other) noexcept {
    using std::swap;
    swap(initialBudget, other.initialBudget);
    swap(currentBudget, other.currentBudget);
    swap(phones, other.phones);
    swap(size, other.size);
    swap(capacity, other.capacity);
}

Store& Store::operator=(const Store& other) {
    if (this != &other) {
        Store temp(other);
        swap(temp);
    }
    return *this;
}

Store::~Store() noexcept {
    freeDynSt();
}

bool Store::addPhone(const Phone& phoneToAdd) {
    double price = phoneToAdd.getPrice();

    if (currentBudget < price) {
        std::cout << "Not enough budget to add: ";
        phoneToAdd.print();
        return false;
    }
    if (size == capacity) {
        resize();
    }
    currentBudget -= price;
    phones[size++] = phoneToAdd.clone();

    std::cout << "Successfully added: ";
    phoneToAdd.print();
    return true;
}

void Store::removeAt(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Internal error: removeAt index out of range.");
    }
    currentBudget += phones[index]->getPrice();
    delete phones[index];
    for (size_t i = index; i < size - 1; ++i) {
        phones[i] = phones[i + 1];
    }
    size--;
}

bool Store::removePhone(const char* model, const char* brand) {
    for (size_t i = 0; i < size; ++i) {
        if (strcmp(phones[i]->getModel(), model) == 0 && strcmp(phones[i]->getBrand(), brand) == 0) {
            std::cout << "Successfully removed(sold): ";
            phones[i]->print();
            removeAt(i); 
            return true;
        }
    }
    std::cout << brand << " " << model << " was not found in the store." << std::endl;
    return false;
}

void Store::printStatus() const {
    std::cout << "\nStatus of the store: " << std::endl;
    std::cout << "Initial budget: " << initialBudget << " lv." << std::endl;
    std::cout << "Current budget: " << currentBudget << " lv." << std::endl;
    std::cout << "Availability (" << size << " phones)" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << "  ";
        phones[i]->print();
    }
}

void Store::sellCheapestSamsung() {
    bool samsungFound = false;
    size_t cheapestIndex = 0;
    double minPrice = 0.0;

    for (size_t i = 0; i < size; ++i) {
        if (strcmp(phones[i]->getBrand(), "Samsung") == 0) {
            double currentPrice = phones[i]->getPrice();
            if (!samsungFound || currentPrice < minPrice) {
                samsungFound = true;
                minPrice = currentPrice;
                cheapestIndex = i;
            }
        }
    }

    if (samsungFound) {
        std::cout << "Selling the cheapest Samsung: ";
        phones[cheapestIndex]->print();
        removeAt(cheapestIndex); 
    } else {
        std::cout << "No available Samsung phones in the store." << std::endl;
    }
}
