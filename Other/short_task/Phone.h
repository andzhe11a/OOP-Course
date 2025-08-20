#pragma once

class Phone {
public:
    Phone(const char* model, const char* brand, double price);
    Phone(const Phone& other);
    Phone& operator=(const Phone& other);
    virtual ~Phone() noexcept;

    const char* getModel() const;
    const char* getBrand() const;

    virtual double getPrice() const;
    virtual void print() const;
    virtual Phone* clone() const;

    void swap(Phone& other) noexcept;

private:
    char* model = nullptr;
    char* brand = nullptr;
    double price = 0.0;

    void copyDyn(const Phone& other);
    void freeDyn();
};
