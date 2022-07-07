//
// Created by Velasco on 7/7/2022.
//


#include "Course.h"
#include <iostream>

//constructor
Course::Course(const string &courseCode, const string &courseName, unsigned int courseSemester) : courseCode(
        courseCode), courseName(courseName), courseSemester(courseSemester) {}

// copy constructor
Course::Course(const Course &copy) {
    this->courseCode = copy.courseCode;
    this->courseName = copy.courseName;
    this->courseSemester = copy.courseSemester;
}

// destructor
Course::~Course() {

}

// setters
void Course::setCourseCode(const string &courseCode) {
    Course::courseCode = courseCode;
}

void Course::setCourseName(const string &courseName) {
    Course::courseName = courseName;
}

void Course::setCourseSemester(unsigned int courseSemester) {
    Course::courseSemester = courseSemester;
}


// getters

const string &Course::getCourseCode() const {
    return courseCode;
}

const string &Course::getCourseName() const {
    return courseName;
}

unsigned int Course::getCourseSemester() const {
    return courseSemester;
}
