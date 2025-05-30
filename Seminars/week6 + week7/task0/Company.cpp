#include "Company1.h"
#include <iostream>
#include <cstring>

Company::Company() : name(nullptr), boss(nullptr), workers(nullptr), capacity(0), count(0) {}

Company::Company(const char* cname, Worker* cboss) : boss(cboss), count(0), capacity(10) {
    name = new char[strlen(cname) + 1];
    strcpy(name, cname);

    workers = new Worker*[capacity];
    boss->setBoss(boss);
    boss->setCompany(this);
    workers[count++] = boss;
}

Company::Company(const Company& other) {
    copy(other);
}

Company& Company::operator=(const Company& other) {
    if (this != &other) {
        freeDyn();
        copy(other);
    }
    return *this;
}

Company::~Company() {
    freeDyn();
}

void Company::freeDyn() {
    delete[] name;
    for (int i = 0; i < count; i++) {
        delete workers[i];
    }
    delete[] workers;
}

void Company::copy(const Company& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    boss = other.boss;
    count = other.count;
    capacity = other.capacity;
    workers = new Worker*[capacity];
    for (int i = 0; i < count; i++) {
        workers[i] = new Worker(*other.workers[i]);
    }
}

void Company::addWorker(Worker* worker) {
    if (count >= capacity) {
        capacity *= 2;
        Worker** newArr = new Worker*[capacity];
        for (int i = 0; i < count; ++i)
            newArr[i] = workers[i];
        delete[] workers;
        workers = newArr;
    }
    worker->setCompany(this);
    workers[count++] = worker;
}

void Company::printWorkers() const {
    std::cout << "Company: " << name << "\nWorkers:\n";
    for (int i = 0; i < count; ++i) {
        workers[i]->print();
    }
}
