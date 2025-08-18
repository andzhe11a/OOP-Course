#include "Tire.h"
#include <stdexcept>

Tire::Tire(const char *manufacturer, const char *description,
           unsigned width, unsigned profile, unsigned diameter)
           : CarPart(manufacturer, description), width(width), profile(profile), diameter(diameter){
    check();
}

void Tire::check() const {
    if (width < 155 || width > 365)
        throw std::invalid_argument("Invalid tire width!");
    if (profile < 30 || profile > 80)
        throw std::invalid_argument("Invalid tire profile!");
    if (diameter < 13 || diameter > 21)
        throw std::invalid_argument("Invalid diameter of the tire!");
}

void Tire::print(std::ostream& os) const {
    CarPart::print(os);
    os << " – " << width << "/" << profile << "R" << diameter;
}
