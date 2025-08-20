#include <iostream>
#include <cstring>
#include "Store.h"
#include "Phone.h"

void Store::copyDynSt(const Store& other) {
    phones = new Phone*[capacity];
    for (size_t i = 0; i < size; ++i) {
        phones[i] = other.phones[i]->clone();
    }
}

void Store::free() {
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

Store& Store::operator=(const Store& other) {
    if (this != &other) {
        Store temp(other);
        std::swap(initialBudget, temp.initialBudget);
        std::swap(currentBudget, temp.currentBudget);
        std::swap(phones, temp.phones);
        std::swap(size, temp.size);
        std::swap(capacity, temp.capacity);
    }
    return *this;
}

Store::~Store() noexcept {
    free();
}

bool Store::addPhone(const Phone& phoneToAdd) {
    double price = phoneToAdd.getPrice();

    if (currentBudget >= price) {
        if (size == capacity) {
            resize();
        }

        currentBudget -= price;
        phones[size] = phoneToAdd.clone(); 
        size++;

        std::cout << "Successfully added: ";
        phoneToAdd.print();
        return true;
    } else {
        std::cout << "Not enough budget to add: ";
        phoneToAdd.print();
        return false;
    }
}

bool Store::removePhone(const char* model, const char* brand) {
    for (size_t i = 0; i < size; ++i) {
        if (strcmp(phones[i]->getModel(), model) == 0 && strcmp(phones[i]->getBrand(), brand) == 0) {
            std::cout << "Successfully removed(sold): ";
            phones[i]->print();

            currentBudget += phones[i]->getPrice();
            delete phones[i];

            for (size_t j = i; j < size - 1; ++j) {
                phones[j] = phones[j + 1];
            }
            size--;

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
    Phone* cheapestSamsung = nullptr;
    double minPrice = -1.0;

    for (size_t i = 0; i < size; ++i) {
        if (strcmp(phones[i]->getBrand(), "Samsung") == 0) {
            double currentPrice = phones[i]->getPrice();
            if (cheapestSamsung == nullptr || currentPrice < minPrice) {
                minPrice = currentPrice;
                cheapestSamsung = phones[i];
            }
        }
    }

    if (cheapestSamsung != nullptr) {
        removePhone(cheapestSamsung->getModel(), cheapestSamsung->getBrand());
    } else {
        std::cout << "No available Samsung phones in the store." << std::endl;
    }
}
