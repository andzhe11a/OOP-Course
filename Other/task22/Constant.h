#pragma once
#include "MathExpression.h"

template <typename T>
class Constant : public MathExpression<T> {
public:
    Constant(const T& value) : val(value) {}

    T value() const override {
        return val;
    }

    void print() const override {
        std::cout << val;
    }
private:
    T val;
};
