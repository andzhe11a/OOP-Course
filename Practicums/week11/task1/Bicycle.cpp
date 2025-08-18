#include "Bicycle.h"

Bicycle::Bicycle(const char* color, const char* brand, unsigned year, unsigned seatCount, unsigned maxSpeed,
                 unsigned speedCount, bool hasLights, bool hasBell)
    : Vehicle(color, brand, year, seatCount, maxSpeed),
      speedCount(speedCount), hasLights(hasLights), hasBell(hasBell) {}

unsigned Bicycle::getSpeedCount() const {
    return speedCount;
}

bool Bicycle::hasLightsFunc() const {
    return hasLights;
}

bool Bicycle::hasBellFunc() const {
    return hasBell;
}

std::ostream& operator<<(std::ostream& os, const Bicycle& bike) {
    os << static_cast<const Vehicle&>(bike) << "\n"
       << "Speed Count: " << bike.speedCount << "\n"
       << "Has Lights: " << (bike.hasLights ? "Yes" : "No") << "\n"
       << "Has Bell: " << (bike.hasBell ? "Yes" : "No");
    return os;
}
