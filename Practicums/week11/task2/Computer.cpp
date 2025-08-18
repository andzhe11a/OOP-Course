#include "Computer.h"
#include <cstring>

void Computer::copyDyn(const Computer& other) {
    videoCardModel = new char[strlen(other.videoCardModel) + 1];
    strcpy(videoCardModel, other.videoCardModel);

    cpuPower = other.cpuPower;
    powerSupply = other.powerSupply;
    ram = other.ram;
}

void Computer::freeDyn() {
    delete[] videoCardModel;
    videoCardModel = nullptr;
}

Computer::Computer(double cpuPower, const char* videoCardModel, unsigned powerSupply, unsigned ram)
    : cpuPower(cpuPower), powerSupply(powerSupply), ram(ram) {
    setVideoCardModel(videoCardModel);
}

Computer::Computer(const Computer& other) {
    copyDyn(other);
}

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        freeDyn();
        copyDyn(other);
    }
    return *this;
}

Computer::~Computer() noexcept {
    freeDyn();
}

void Computer::setCpuPower(double cpupower) {
    cpuPower = cpupower;
}

void Computer::setVideoCardModel(const char* videocardmodel) {
    if (videocardmodel == nullptr) {
        throw std::invalid_argument("bad model name");
    }

    char* temp = new char[strlen(videocardmodel) + 1];
    strcpy(temp, videocardmodel);
    delete[] videoCardModel;

    videoCardModel = temp;
}

void Computer::setPowerSupply(unsigned powersupply) {
    powerSupply = powersupply;
}

void Computer::setRam(unsigned _ram) {
    ram = _ram;
}

double Computer::getCpuPower() const {
    return cpuPower;
}

const char* Computer::getVideoCardModel() const {
    return videoCardModel;
}

unsigned Computer::getPowerSupply() const {
    return powerSupply;
}

unsigned Computer::getRam() const {
    return ram;
}
