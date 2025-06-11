#include "Max.h"

template <typename T>
Max<T>::Max() : count(0) {
    for (size_t i = 0; i < 10; ++i) {
        expressions[i] = nullptr;
    }
}

template <typename T>
Max<T>::~Max() {
    for (size_t i = 0; i < count; ++i) {
        delete expressions[i];
    }
}

template <typename T>
void Max<T>::add(MathExpression<T>* expr) {
    if (count < 10 && expr != nullptr) {
        expressions[count++] = expr;
    }
}

template <typename T>
T Max<T>::value() const {
    if (count == 0)
        return T{};

    T maxVal = expressions[0]->value();
    for (size_t i = 1; i < count; ++i) {
        T val = expressions[i]->value();
        if (val > maxVal)
            maxVal = val;
    }
    return maxVal;
}

template <typename T>
void Max<T>::print() const {
    std::cout << "max(";
    for (size_t i = 0; i < count; ++i) {
        expressions[i]->print();
        if (i < count - 1)
            std::cout << ", ";
    }
    std::cout << ")";
}

template class Max<int>;
template class Max<double>;
