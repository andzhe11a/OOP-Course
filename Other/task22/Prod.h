#pragma once
#include "MathExpression.h"

template <typename T>
class Prod : public MathExpression<T> {
public:
    Prod(MathExpression<T>* l, MathExpression<T>* r);
    ~Prod() override;

    T value() const override;
    void print() const override;

private:
    MathExpression<T>* left;
    MathExpression<T>* right;
};
