#include "Average.h"
#include <iostream>

template <typename T>
Average<T>::Average() : count(0) {
    for (size_t i = 0; i < 10; ++i)
        expressions[i] = nullptr;
}

template <typename T>
Average<T>::~Average() {
    for (size_t i = 0; i < count; ++i)
        delete expressions[i];
}

template <typename T>
void Average<T>::add(MathExpression<T>* expr) {
    if (count < 10 && expr != nullptr)
        expressions[count++] = expr;
}

template <typename T>
T Average<T>::value() const {
    if (count == 0)
        return T{};

    T sum = T{};
    for (size_t i = 0; i < count; ++i)
        sum += expressions[i]->value();

    return sum / T(count);
}

template <typename T>
void Average<T>::print() const {
    std::cout << "avg(";
    for (size_t i = 0; i < count; ++i) {
        expressions[i]->print();
        if (i < count - 1)
            std::cout << ", ";
    }
    std::cout << ")";
}

template class Average<int>;
template class Average<double>;
