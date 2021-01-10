#ifndef COURSE_H
#define COURSE_H

#include "Array.h"
#include "List.h"

struct Course {
    int id;
    ClassList classes;//change to class list!!!

    Course(int id): id(id), classes()
    {
    }
    Course(const Course& other) = default;
    Course& operator=(const Course& other) = default;
    ~Course() = default;

    bool operator==(const Course &other) {
        return id == other.id;
    }
};


#endif //COURSE_H
