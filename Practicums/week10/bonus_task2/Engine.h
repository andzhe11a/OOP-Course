#pragma once
#include "CarPart.h"

class Engine : public CarPart{
public:
    Engine(const char* manufacturer, const char* description,
           unsigned horsePower);

    void print(std::ostream& os) const override;

private:
    unsigned horsePower = 0;
};
