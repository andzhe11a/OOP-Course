#pragma once
#include "Phone.h"

class Smartphone : public Phone {
public:
    Smartphone(const char* model, const char* brand, double price, const char* os, unsigned memory);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    ~Smartphone() noexcept override;

    double getPrice() const override;
    void print() const override;
    Phone* clone() const override;

private:
    char* os = nullptr;
    unsigned memory = 0;

    void copyDynS(const Smartphone& other);
    void freeDynS() const;
};