#pragma once
#include "MathExpression.h"

template <typename T>
class Average : public MathExpression<T> {
public:
    Average();
    ~Average() override;
    void add(MathExpression<T>* expr);

    T value() const override;
    void print() const override;

private:
    MathExpression<T>* expressions[10];
    size_t count;
};
