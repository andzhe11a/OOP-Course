#pragma once
#include <iostream>

class Student {
public:
    Student();
    Student(const char* name, unsigned facNum, unsigned course);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student() noexcept;

    const char* getName() const;
    unsigned getFacNum() const;
    unsigned getCourse() const;

    void setName(const char* name);
    void setFacNum(unsigned facNum);
    void setCourse(unsigned course);

    void print() const;
private:
    char* name = nullptr;
    unsigned facNum;
    unsigned course;

    void copyDyn(const Student& other);
    void freeDyn();
};
