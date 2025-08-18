#pragma once
#include "CarPart.h"

class Battery : public CarPart{
public:
    Battery();
    Battery(const char* manufacturer, const char* description,
            unsigned capacity, const char* batteryId);
    Battery(const Battery& other);
    Battery& operator=(const Battery& other);
    ~Battery() noexcept override;

    void print(std::ostream& os) const override;

private:
    unsigned capacity = 0;
    char* batteryId = nullptr;

    void copyDyn(const Battery& other);
    void freeDyn();
};
