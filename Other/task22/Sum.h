#pragma once
#include "MathExpression.h"

template <typename T>
class Sum : public MathExpression<T> {
public:
    Sum(MathExpression<T>* l, MathExpression<T>* r);
    ~Sum() override;

    T value() const override;
    void print() const override;

private:
    MathExpression<T>* left;
    MathExpression<T>* right;
};
