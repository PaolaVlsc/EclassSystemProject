//
// Created by Velasco on 7/7/2022.
//

#include "Person.h"
#include <iostream>
#include <cstring>

using namespace std;

// constructor
Person::Person(const string &code, const char *lastName, const char *firstName, const string &email,
               const list<Course *> &coursesList) {
    this->code = code;

    // last name and first name
    try {
        this->lastName = new char[strlen(lastName) + 1];
        this->firstName = new char[strlen(firstName) + 1];
    }
    catch (std::bad_alloc &exception) {
        cout << exception.what() << endl;
        exit(EXIT_FAILURE);
    }

    strncpy(this->lastName, lastName, strlen(lastName) + 1);
    strncpy(this->firstName, firstName, strlen(firstName) + 1);

    this->email = email;
    this->coursesList = coursesList;
}

// copy constructor
Person::Person(const Person &copy) {
    this->code = copy.code;

    // last name and first name
    try {
        this->lastName = new char[strlen(copy.lastName) + 1];
        this->firstName = new char[strlen(copy.firstName) + 1];
    }
    catch (std::bad_alloc &exception) {
        cout << exception.what() << endl;
        exit(EXIT_FAILURE);
    }

    strncpy(this->lastName, copy.lastName, strlen(copy.lastName) + 1);
    strncpy(this->firstName, copy.firstName, strlen(copy.firstName) + 1);

    this->email = copy.email;
    this->coursesList = copy.coursesList;

}

// destructor
Person::~Person() {
    delete[]this->lastName;

    delete[]this->firstName;
}


// setters
void Person::setCode(const string &code) {
    this->code = code;
}

void Person::setLastName(const char *lastName) {
    delete [] this->lastName;
    // last name and first name
    try {
        this->lastName = new char[strlen(lastName) + 1];
    }
    catch (std::bad_alloc &exception) {
        cout << exception.what() << endl;
        exit(EXIT_FAILURE);
    }
    strncpy(this->lastName, lastName, strlen(lastName) + 1);
}

void Person::setFirstName(const char *firstName) {
    delete [] this->firstName;

    // first name
    try {
        this->firstName = new char[strlen(firstName) + 1];
    }
    catch (std::bad_alloc &exception) {
        cout << exception.what() << endl;
        exit(EXIT_FAILURE);
    }
    strncpy(this->firstName, firstName, strlen(firstName) + 1);
}

void Person::setEmail(const string &email) {
    this->email = email;
}

void Person::setCoursesList(const list<Course *> &coursesList) {
    this->coursesList = coursesList;
}

// getters
const string &Person::getCode() const {
    return code;
}

char *Person::getLastName() const {
    return this->lastName;
}

char *Person::getFirstName() const {
    return this->firstName;
}

const string &Person::getEmail() const {
    return email;
}

const list<Course *> &Person::getCoursesList() const {
    return coursesList;
}
#include <algorithm>

bool Person::hasCourse(Course &course) {
//    list <Course *>::iterator it;
//    for (it = coursesList.begin (); it != coursesList.end (); it++)
//        if (*it == &course)
//            return true;
//    return false;

    return find(coursesList.begin(), coursesList.end(), &course) != coursesList.end();
}

//template<typename T>
//T &Person::operator=(const T &) {
//    //return <#initializer#>;
//    return
//}



