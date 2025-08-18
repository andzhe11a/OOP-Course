#pragma once
#include <iostream>

class CarPart {
public:
    CarPart();
    CarPart(const char* manufacturer, const char* description);
    CarPart(const CarPart& other);
    CarPart& operator=(const CarPart& other);
    virtual ~CarPart() noexcept;

    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);

protected:
    unsigned getId() const;
    const char* getManufacturer() const;
    const char* getDescription() const;

private:
    static unsigned nextId;
    unsigned id = 0;
    char* manufacturer = nullptr;
    char* description = nullptr;

    void copyDyn(const CarPart& other);
    void freeDyn();
};
