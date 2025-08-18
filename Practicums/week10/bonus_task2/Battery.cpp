#include "Battery.h"
#include <cstring>

void Battery::copyDyn(const Battery &other) {
    batteryId = new char[strlen(other.batteryId) + 1];
    strcpy(batteryId, other.batteryId);
}

void Battery::freeDyn() {
    delete[] batteryId;
    batteryId = nullptr;
}

Battery::Battery() : capacity(0), batteryId(nullptr) {}

Battery::Battery(const char *manufacturer, const char *description, unsigned capacity, const char *batteryId)
    : CarPart(manufacturer, description), capacity(capacity) {
    this->batteryId = new char[strlen(batteryId) + 1];
    strcpy(this->batteryId, batteryId);
}

Battery::Battery(const Battery &other)
    : CarPart(other), capacity(other.capacity) {
    copyDyn(other);
}

Battery &Battery::operator=(const Battery &other) {
    if (this != &other) {
        Battery temp(other);
        std::swap(batteryId, temp.batteryId);
        std::swap(capacity, temp.capacity);
    }
    return *this;
}

Battery::~Battery() noexcept {
    freeDyn();
}

void Battery::print(std::ostream& os) const {
    CarPart::print(os);
    os << " – " << capacity << " Ah";
}
