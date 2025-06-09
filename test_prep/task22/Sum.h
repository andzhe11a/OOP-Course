#pragma once
#include "MathExpression.h"

template <typename T>
class Sum : public MathExpression<T> {
private:
    MathExpression<T>* left;
    MathExpression<T>* right;

public:
    Sum(MathExpression<T>* l, MathExpression<T>* r);
    ~Sum() override;

    T value() const override;
    void print() const override;
};
