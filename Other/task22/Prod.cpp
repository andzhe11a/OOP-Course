#include "Prod.h"
#include <iostream>

template <typename T>
Prod<T>::Prod(MathExpression<T>* l, MathExpression<T>* r)
    : left(l), right(r) {}

template <typename T>
Prod<T>::~Prod() {
    delete left;
    delete right;
}

template <typename T>
T Prod<T>::value() const {
    return left->value() * right->value();
}

template <typename T>
void Prod<T>::print() const {
    std::cout << "(";
    left->print();
    std::cout << " * ";
    right->print();
    std::cout << ")";
}

template class Prod<int>;
template class Prod<double>;
