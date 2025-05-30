#include "Student.h"
#include <cstring>

void Student::copyDyn(const Student &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Student::freeDyn() {
    delete[] name;
    name = nullptr;
}

Student::Student() : name(nullptr), facNum(0), course(0) {}

Student::Student(const char *name, unsigned facNum, unsigned course)
    : facNum(facNum), course(course) {
    setName(name);
}

Student::Student(const Student &other) : facNum(other.facNum), course(other.course) {
    copyDyn(other);
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        Student temp(other);
        std::swap(name, temp.name);
        std::swap(facNum, temp.facNum);
        std::swap(course, temp.course);
    }
    return *this;
}

Student::~Student() noexcept {
    freeDyn();
}

const char* Student::getName() const {
    return name;
}

unsigned Student::getFacNum() const {
    return facNum;
}

unsigned Student::getCourse() const {
    return course;
}

void Student::setName(const char* _name) {
    if (_name == nullptr)
    {
        throw std::invalid_argument("Name is invalid");
    }

    char* temp = new char[strlen(_name) + 1];
    strcpy(temp, _name);
    delete[] name;

    name = temp;
}

void Student::setFacNum(unsigned fn) {
    facNum = fn;
}

void Student::setCourse(unsigned c) {
    course = c;
}

void Student::print() const {
    std::cout << "Name: " << name << "\nFaculty number: " << facNum << "\nCourse: " << course << "\n";
}
