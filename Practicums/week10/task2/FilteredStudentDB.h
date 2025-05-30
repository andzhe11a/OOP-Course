#pragma once
#include "StudentDB.h"

class FilteredStudentDB : public StudentDB {
public:
    void filterByCourse(unsigned course);
    void limit(unsigned count);
};
