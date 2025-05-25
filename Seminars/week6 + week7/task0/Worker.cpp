#include "Worker1.h"
#include "Company1.h"
#include <iostream>
#include <cstring>

int Worker::nextId = 1;

Worker::Worker() : id(nextId++), firstName(nullptr), lastName(nullptr), salary(0), boss(nullptr), company(nullptr) {}

Worker::Worker(const char* fname, const char* lname, double sal, Worker* boss)
    : id(nextId++), firstName(nullptr), lastName(nullptr), salary(sal), boss(boss), company(nullptr) {
    setFirstName(fname);
    setLastName(lname);
}

Worker::Worker(const Worker& other) {
    copy(other);
}

Worker& Worker::operator=(const Worker& other) {
    if (this != &other) {
        freeDyn();
        copy(other);
    }
    return *this;
}

Worker::~Worker() {
    freeDyn();
}

void Worker::freeDyn() {
    delete[] firstName;
    delete[] lastName;
}

void Worker::copy(const Worker& other) {
    id = nextId++;
    salary = other.salary;
    boss = other.boss;
    company = other.company;

    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);

    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);
}

void Worker::setFirstName(const char* fname) {
    if(fname == nullptr) {
        throw std::invalid_argument("bad name");
    }

    char* temp = new char[strlen(fname) + 1];
    strcpy(temp, fname);
    delete[] firstName;

    firstName = temp;
}

void Worker::setLastName(const char* lname) {
    if(lname == nullptr) {
        throw std::invalid_argument("bad name");
    }

    char* temp = new char[strlen(lname) + 1];
    strcpy(temp, lname);
    delete[] lastName;

    lastName = temp;
}

void Worker::setSalary(double s) {
    salary = s;
}

void Worker::setBoss(Worker* b) {
    boss = b;
}

void Worker::setCompany(Company* c) {
    company = c;
}

const char* Worker::getFirstName() const {
    return firstName;
}

const char* Worker::getLastName() const {
    return lastName;
}

double Worker::getSalary() const {
    return salary;
}

int Worker::getId() const {
    return id;
}

Worker* Worker::getBoss() const {
    return boss;
}

Company* Worker::getCompany() const {
    return company;
}

bool Worker::isBoss() const {
    return boss == this;
}

void Worker::print() const {
    std::cout << "ID: " << id << ", Name: " << firstName << ' ' << lastName
              << ", Salary: " << salary;
    if (boss)
        std::cout << ", Boss: " << boss->getFirstName();
    std::cout << std::endl;
}
