#include <iostream>
#include "Student.h"
#include "StudentDB.h"
#include "FilteredStudentDB.h"

int main() {
    Student s1("Ivan Ivanov", 12345, 1);
    Student s2("Maria Petrova", 12346, 2);
    Student s3("Georgi Georgiev", 12347, 3);
    Student s4("Petar Petrov", 12349, 1);

    FilteredStudentDB db;
    db.add(s1);
    db.add(s2);
    db.add(s3);
    db.add(s4);

    std::cout << "--- All Students ---\n";
    db.display();

    std::cout << "\n--- Find student with FN 12346 ---\n";
    const Student* found = db.find(12346);
    if (found) {
        found->print();
    }
    else {
        std::cout << "Student not found.\n";
    }

    db.remove(12347);
    std::cout << "\n--- After removing FN 12347 ---\n";
    db.display();

    std::cout << "\n--- Only 1st Course students ---\n";
    db.filterByCourse(1);
    db.display();

    std::cout << "\n--- Only first 3 of the students ---\n";
    db.limit(3);
    db.display();

    return 0;
}
