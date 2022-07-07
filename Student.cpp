//
// Created by Velasco on 7/7/2022.
//

/*
 * MENU
 * constructor
 * copy constructor
 * destructor
 * setters and getters
 * virtual print()
 */
#include "Student.h"

// constructor
Student::Student(const string &code, const char *lastName, const char *firstName, unsigned int semester,
                 const string &email, const list<Course *> &coursesList) :
        Person(code, lastName, firstName, email, coursesList) {
    this->semester = semester;
}

// copy constructor
Student::Student(const Student &copy) : Person(copy) {
    this->semester = copy.semester;
}

// destructor
Student::~Student() {

}

// setters and getters
unsigned int Student::getSemester() const {
    return this->semester;
}

void Student::setSemester(unsigned int semester) {
    this->semester = semester;
}

// FIXME 01: virtual print()