#pragma once
#include <iostream>

template <typename T>
class MathExpression {
public:
    virtual ~MathExpression() = default;

    virtual T value() const = 0;

    virtual void print() const = 0;
};
