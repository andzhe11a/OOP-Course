#pragma once

//returns an array
template <typename T>
struct DataSourceArray {
    T* array;
    size_t size;
};

template <typename T>
class DataSource {
public:
    virtual ~DataSource() noexcept = default;

    // operator() calls getNext to get the next elem
    T operator()() {
        return getNext();
    }

    // converts the elem into a bool and calls hasNext to check if the next elem exists
    operator bool() const {
        return hasNext();
    }

    virtual T getNext() = 0; // gets one elem

    virtual DataSourceArray<T> getNext(size_t count) = 0; //gets consecutive elements

    virtual bool hasNext() = 0; // checks if next elem exists

    virtual bool reset() = 0; // resets the source (if possible (t/f))

    virtual DataSource<T>* clone() const = 0; // returns a copy of the current elem (polymorphism)
};

//operator>> for elem extraction
template <typename T>
DataSource<T>& operator>>(DataSource<T>& src, T& value) {
    value = src.getNext();
    return src;
}
