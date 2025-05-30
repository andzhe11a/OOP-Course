#include "FilteredStudentDB.h"

void FilteredStudentDB::filterByCourse(unsigned course) {
    size_t index = 0;

    for (size_t i = 0; i < size; ++i) {
        if (students[i].getCourse() == course) {
            students[index++] = students[i];
        }
    }

    size = index;
}

void FilteredStudentDB::limit(unsigned count) {
    if (count < size) {
        size = count;
    }
}
