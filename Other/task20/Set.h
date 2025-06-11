#pragma once
#include "Container.h"

template <typename T>
class Set : public Container<T> {
public:
    Set(Container<T>* newStore) : store(newStore) {}

    bool member(const T& element) const override {
        return store->member(element);
    }

    bool add(const T& element) override {
        if (store->member(element))
            return false;
        return store->add(element);
    }

    bool remove(const T& element) override {
        return store->remove(element);
    }

    int getSize() const override {
        return store->getSize();
    }

    T& operator[](int i) override {
        return (*store)[i];
    }

    Container<T>* clone() const override {
        return new Set<T>(store->clone());
    }

    ~Set() noexcept override {
        delete store;
    }

private:
    Container<T>* store;
};
