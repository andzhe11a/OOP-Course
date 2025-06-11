#pragma once
#include "MathExpression.h"

template <typename T>
class Max : public MathExpression<T> {
public:
    Max();
    ~Max() override;

    void add(MathExpression<T>* expr);

    T value() const override;
    void print() const override;

private:
    MathExpression<T>* expressions[10];
    size_t count;
};
