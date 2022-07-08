//
// Created by Velasco on 7/7/2022.
//

#include "Professor.h"

using std::endl;

Professor::Professor(const string &code, const char *lastName, const char *firstName, const string &speciality,
                     const string &email,
                     const list<Course *> &coursesList) : Person(code, lastName, firstName, email, coursesList) {
    this->speciality = speciality;
}

Professor::Professor(const Professor &copy) : Person(copy) {
    this->speciality = copy.speciality;
}

Professor::~Professor() {

}

const string &Professor::getSpeciality() const {
    return this->speciality;
}

void Professor::setSpeciality(const string &speciality) {
    this->speciality = speciality;
}

void Professor::print(ostream &stream) const {
    stream << endl << "ID: " << getCode() <<
           "\tLast Name: " << getLastName() <<
           "\tFirst Name: " << getLastName() <<
           "\tSpeciality: " << getSpeciality() <<
           "\tEmail: " << getEmail() << endl <<
           "Courses: " << endl << getCoursesList() << endl;
}

