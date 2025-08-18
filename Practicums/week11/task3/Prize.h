#pragma once
#include <iostream>

class Prize {
public:
    Prize(double price, unsigned points);
    virtual ~Prize() noexcept;

    double getPrice() const;
    unsigned getPoints() const;

    virtual void visualize() const = 0;

protected:
    double price;
    unsigned points;
};

