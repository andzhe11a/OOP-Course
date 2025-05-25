#pragma once
#include "Worker1.h"

class Company {
public:
    Company();
    Company(const char* name, Worker* boss);
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void addWorker(Worker* worker);
    void printWorkers() const;

private:
    char* name;
    Worker* boss;
    Worker** workers;
    int capacity;
    int count;

    void copy(const Company& other);
    void freeDyn();
};
