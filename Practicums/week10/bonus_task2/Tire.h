#pragma once
#include "CarPart.h"

class Tire : public CarPart{
public:
    Tire(const char* manufacturer, const char* description,
        unsigned width, unsigned profile, unsigned diameter);

    void print(std::ostream& os) const override;

private:
    unsigned width = 0;
    unsigned profile = 0;
    unsigned diameter = 0;

    void check() const;
};
