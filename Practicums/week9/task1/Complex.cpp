#include "Complex.h"
#include <stdexcept>

Complex::Complex(double r, double i) : real(r), imag(i) {}


double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}


Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(
        real * other.real - imag * other.imag,
        real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex &other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0)
        throw std::runtime_error("Division by zero");
    return Complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator);
}


Complex Complex::conjugate() const {
    return Complex(real, -imag);
}


bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator<(const Complex& other) const {
    return (real < other.real) || (real == other.real && imag < other.imag);
}

bool Complex::operator<=(const Complex& other) const {
    return *this < other || *this == other;
}

bool Complex::operator>(const Complex& other) const {
    return other < *this;
}

bool Complex::operator>=(const Complex& other) const {
    return other <= *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    return is >> c.real >> c.imag;
}
