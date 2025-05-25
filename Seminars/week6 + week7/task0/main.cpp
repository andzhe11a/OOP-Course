#include "Worker1.h"
#include "Company1.h"
#include <iostream>

int main() {
    Worker* boss = new Worker("Ivan", "Ivanov", 5000.0, nullptr);

    Company company("TechX", boss);

    Worker* w1 = new Worker("Maria", "Georgieva", 3000.0, boss);
    Worker* w2 = new Worker("Petar", "Petrov", 2800.0, boss);
    Worker* w3 = new Worker("Elena", "Dimitrova", 3200.0, boss);

    company.addWorker(w1);
    company.addWorker(w2);
    company.addWorker(w3);

    company.printWorkers();

    return 0;
}
