#include "StudentTicket.h"
#include "GroupTicket.h"

int main() {
    Ticket regular("Hamlet", 40.0);
    StudentTicket student("Hamlet", 40.0);
    GroupTicket group("Hamlet", 40.0);

    std::cout << "--- Regular ---\n";
    regular.print();

    std::cout << "\n--- Student ---\n";
    student.print();

    std::cout << "\n--- Group ---\n";
    group.print();

    return 0;
}
