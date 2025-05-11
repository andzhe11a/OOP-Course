#include "MyString.h"
#include <stdexcept>
#include <cstring>

void MyString::checkCapacity(size_t newCap)
{
    if (newCap <= cap)
    {
        return;
    }
    cap = newCap * 2;
    char* newData = new char[cap + 1];
    std::strcpy(newData, data);
    delete[] data;
    data = newData;
}

MyString::MyString()
    :length(0), cap(15)
{
    data = new char[cap + 1];
    data[0] = '\0';
}

MyString::MyString(const char* str)
{
    length = std::strlen(str);
    cap = length + 15;
    data = new char[cap + 1];
    std::strcpy(data, str);
}

MyString::MyString(const MyString& other)
    :length(other.length), cap(other.cap)
{
    data = new char[cap + 1];
    std::strcpy(data, other.data);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete[] data;
        length = other.length;
        cap = other.cap;
        data = new char[cap + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

MyString::~MyString()
{
    delete[] data;
}

char MyString::at(size_t index) const {
    if (index >= length)
        throw std::out_of_range("Index out of range");
    return data[index];
}

char MyString::front() const {
    if (length == 0)
    {
        throw std::out_of_range("Empty string");
    }
    return data[0];
}

char MyString::back() const {
    if (length == 0)
    {
        throw std::out_of_range("Empty string");
    }
    return data[length - 1];
}

const char* MyString::c_str() const {
    return data;
}

size_t MyString::size() const {
    return length;
}

size_t MyString::capacity() const {
    return cap;
}

bool MyString::empty() const {
    return length == 0;
}

void MyString::clear() {
    length = 0;
    data[0] = '\0';
}

bool MyString::equals(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool MyString::equals(const char* str) const {
    return std::strcmp(data, str) == 0;
}