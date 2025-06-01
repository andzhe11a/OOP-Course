#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const char* color, const char* brand, unsigned year, unsigned seatCount, unsigned maxSpeed,
        unsigned speedCount, bool hasLights, bool hasBell);

    unsigned getSpeedCount() const;
    bool hasLightsFunc() const;
    bool hasBellFunc() const;

    friend std::ostream& operator<<(std::ostream& os, const Bicycle& bike);

private:
    unsigned speedCount = 0;
    bool hasLights = false;
    bool hasBell = false;
};
