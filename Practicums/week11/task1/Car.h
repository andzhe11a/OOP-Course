#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    Car(const char* color, const char* brand, const char* model, unsigned year, unsigned seatCount, unsigned maxSpeed,
        unsigned doorCount, unsigned horsePower);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car() noexcept;

    const char* getModel() const;
    unsigned getDoorCount() const;
    unsigned getHorsePower() const;

    friend std::ostream& operator<<(std::ostream& os, const Car& car);

private:
    char* model = nullptr;
    unsigned doorCount = 0;
    unsigned horsePower = 0;

    void copyDyn(const Car& other);
    void freeDyn();
};
