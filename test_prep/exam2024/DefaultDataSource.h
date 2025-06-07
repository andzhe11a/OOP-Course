#pragma once
#include "DataSource.h"

template <typename T>
class DefaultDataSource : public DataSource<T> {
public:
    virtual T getNext() override {
        return T{}; //default constructor
    }

    virtual DataSourceArray<T> getNext(size_t count) override {
        T* data = new T[count];
        for (size_t i = 0; i < count; i++) {
            data[i] = T{};
        }
        return {data, count};
    }

    virtual bool hasNext() override {
        return true;
    }

    virtual bool reset() override {
        return true;
    }

    virtual DataSource<T>* clone() const override {
        return new DefaultDataSource<T>(*this);
    }
};
