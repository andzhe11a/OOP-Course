#pragma once
#include <cstring>

class MyString {
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    char at(size_t index) const;
    char front() const;
    char back() const;
    const char* c_str() const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    void clear();

    bool equals(const MyString& other) const;
    bool equals(const char* str) const;

private:
    char* data;
    size_t length;
    size_t cap;

    void checkCapacity(size_t newCap);
};