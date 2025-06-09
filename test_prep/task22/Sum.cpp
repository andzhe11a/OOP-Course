#pragma once
#include "Sum.h"
#include <iostream>

template <typename T>
Sum<T>::Sum(MathExpression<T>* l, MathExpression<T>* r)
    : left(l), right(r) {}

template <typename T>
Sum<T>::~Sum() {
    delete left;
    delete right;
}

template <typename T>
T Sum<T>::value() const {
    return left->value() + right->value();
}

template <typename T>
void Sum<T>::print() const {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")";
}

template class Sum<int>;
template class Sum<double>;
