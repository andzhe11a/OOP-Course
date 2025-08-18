#pragma once
#include <iostream>

class Vehicle {
public:
    Vehicle();
    Vehicle(const char* color, const char* brand, unsigned year, unsigned seatCount, unsigned maxSpeed);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    ~Vehicle() noexcept;

    const char* getColor() const;
    const char* getBrand() const;
    unsigned getYear() const;
    unsigned getSeatCount() const;
    unsigned getMaxSpeed() const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);

private:
    char* color = nullptr;
    char* brand = nullptr;
    unsigned year = 0;
    unsigned seatCount = 0;
    unsigned maxSpeed = 0;

    void copyDyn(const Vehicle& other);
    void freeDyn();
};
