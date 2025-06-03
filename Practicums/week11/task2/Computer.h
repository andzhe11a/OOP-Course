#pragma once
#include <iostream>

class Computer {
public:
    Computer(double cpuPower, const char* videoCardModel, unsigned powerSupply, unsigned ram);
    Computer(const Computer& other);
    Computer& operator=(const Computer& other);
    virtual ~Computer() noexcept;

    void setCpuPower(double cpuPower);
    void setVideoCardModel(const char* videoCardModel);
    void setPowerSupply(unsigned powerSupply);
    void setRam(unsigned ram);

    double getCpuPower() const;
    const char* getVideoCardModel() const;
    unsigned getPowerSupply() const;
    unsigned getRam() const;

    virtual void print() const = 0;

    virtual void peripherals() const = 0;

private:
    double cpuPower{};
    char* videoCardModel = nullptr;
    unsigned powerSupply{};
    unsigned ram{};

    void copyDyn(const Computer& other);
    void freeDyn();
};
