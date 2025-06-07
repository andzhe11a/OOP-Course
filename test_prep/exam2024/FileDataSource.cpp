#include "FileDataSource.h"

template <typename T>
FileDataSource<T>::FileDataSource(const char* fileName)
    : fileName(fileName), hasEnough(true) {
    file.open(fileName);
    if (!file.is_open()) {
        hasEnough = false;
    }
}

template <typename T>
FileDataSource<T>::FileDataSource(const FileDataSource& other)
: fileName(fileName), hasEnough(true) {
    file.open(fileName);
    if (!file.is_open()) {
        hasEnough = false;
    }
}

template <typename T>
FileDataSource<T>::~FileDataSource() {
    if (file.is_open()) {
        file.close();
    }
}

template <typename T>
T FileDataSource<T>::getNext() {
    T value{};
    if (!(file >> value)) {
        hasEnough = false;
    }
    return value;
}

template <typename T>
DataSourceArray<T> FileDataSource<T>::getNext(size_t count) {
    T* array = new T[count];
    size_t i = 0;
    for (; i < count && file >> array[i]; ++i);
    return { array, i };
}

template <typename T>
bool FileDataSource<T>::hasNext() {
    return hasEnough && file && !file.eof();
}

template <typename T>
bool FileDataSource<T>::reset() {
    if (file.is_open()) {
        file.close();
    }
    file.open(fileName);
    hasEnough = file.is_open();
    return hasEnough;
}

template <typename T>
DataSource<T>* FileDataSource<T>::clone() const {
    return new FileDataSource<T>(*this);
}

template class FileDataSource<int>;
template class FileDataSource<double>;
