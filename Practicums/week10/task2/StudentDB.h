#pragma once
#include "Student.h"

class StudentDB {
public:
    StudentDB();
    StudentDB(const StudentDB& other);
    StudentDB& operator=(const StudentDB& other);
    ~StudentDB() noexcept;

    void add(const Student& student);
    void remove(unsigned facNum);
    const Student* find(unsigned facNum) const;
    void display() const;
protected:
    Student* students{};
    size_t size{};
private:
    size_t capacity{};

    void resize();
    void copyDyn(const StudentDB& other);
    void freeDyn() const;
};
