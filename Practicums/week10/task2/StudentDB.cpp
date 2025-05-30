#include "StudentDB.h"

void StudentDB::resize() {
    capacity *= 2;
    Student* newStudents = new Student[capacity];

    for (size_t i = 0; i < size; ++i) {
        newStudents[i] = students[i];
    }

    delete[] students;
    students = newStudents;
}

void StudentDB::copyDyn(const StudentDB& other) {
    students = new Student[other.capacity];

    for (size_t i = 0; i < other.size; ++i) {
        students[i] = other.students[i];
    }
}

void StudentDB::freeDyn() const {
    delete[] students;
}

StudentDB::StudentDB() : size(0), capacity(8) {
    students = new Student[capacity];
}

StudentDB::StudentDB(const StudentDB& other) {
    copyDyn(other);
    size = other.size;
    capacity = other.capacity;
}

StudentDB& StudentDB::operator=(const StudentDB& other) {
    if (this != &other) {
        StudentDB temp(other);
        std::swap(students, temp.students);
        std::swap(size, temp.size);
        std::swap(capacity, temp.capacity);
    }
    return *this;
}

StudentDB::~StudentDB() noexcept {
    freeDyn();
}

void StudentDB::add(const Student& student) {
    if (size == capacity)
        resize();
    students[size++] = student;
}

void StudentDB::remove(unsigned facultyNumber) {
    if (facultyNumber == 0)
        throw std::invalid_argument("Invalid faculty number!");

    for (size_t i = 0; i < size; ++i) {
        if (students[i].getFacNum() == facultyNumber) {
            std::swap(students[i], students[--size]);
            return;
        }
    }

    throw std::logic_error("Student not found!");
}

const Student* StudentDB::find(unsigned facultyNumber) const {
    for (size_t i = 0; i < size; ++i) {
        if (students[i].getFacNum() == facultyNumber)
            return &students[i];
    }
    return nullptr;
}

void StudentDB::display() const {
    if (size == 0) {
        std::cout << "Student Database is empty.\n";
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        students[i].print();
    }
}
