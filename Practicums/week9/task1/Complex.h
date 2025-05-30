#pragma once
#include <iostream>

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0);

    double getReal() const;
    double getImag() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex conjugate() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator>=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator<=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
    friend std::istream& operator>>(std::istream& is, Complex& complex);
private:
    double real;
    double imag;
};
