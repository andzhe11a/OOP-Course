#include "Engine.h"

Engine::Engine(const char *manufacturer, const char *description, unsigned horsePower)
               : CarPart(manufacturer, description), horsePower(horsePower) {}

void Engine::print(std::ostream& os) const {
    CarPart::print(os);
    os << " – " << horsePower << " hp";
}
