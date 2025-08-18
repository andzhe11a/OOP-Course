#include "Prize.h"

Prize::Prize(double price, unsigned points)
    : price(price), points(points) {}

Prize::~Prize() noexcept = default;

double Prize::getPrice() const {
    return price;
}

unsigned Prize::getPoints() const {
    return points;
}
