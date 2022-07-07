//
// Created by Velasco on 7/7/2022.
//

#include "EClass.h"

// constructor
// use default

// copy constructor
// use default

// destructor
// use default

// getters
const list<Person *> &EClass::getStudentsAndProfessorsList() const {
    return this->studentsAndProfessorsList;
}

const list<User *> &EClass::getUsersList() const {
    return this->usersList;
}

// setters
void EClass::setStudentsAndProfessorsList(const list<Person *> &studentsAndProfessorsList) {
    this->studentsAndProfessorsList = studentsAndProfessorsList;
}

void EClass::setUsersList(const list<User *> &usersList) {
    this->usersList;
}

// Δημιουργεί καταστάσεις με τους φοιτητές που παρακολουθούν ένα μάθημα
// (v) Να υλοποιηθεί μέθοδος printStudentList() η οποία θα επιστρέφει λίστα φοιτητών οι οποίοι παρακολουθούν ένα μάθημα.
list<Student *> EClass::listOfRegisteredStudentsOnCourse(Course &course) {

    list<Student *> listOfRegisteredStudentsOnCourse;
    Student *student;

    for (Person *const &each: studentsAndProfessorsList) {
        if (each->hasCourse(course)) {
            student = dynamic_cast<Student *>(each);
            if (student != nullptr)
                listOfRegisteredStudentsOnCourse.push_back(student);
        }
    }

    return listOfRegisteredStudentsOnCourse;
}

// Δέχεται το όνομα και το συνθηματικό ενός χρήστη του συστήματος και
// επιστρέφει τα στοιχεία του χρήστη στον οποίο αντιστοιχούν (αν είναι σωστά).
// login
Person *EClass::listData(const string &username, const string &password) {

    for (User *&each: usersList) {
        if (strcmp(each->getUsername().c_str(), username.c_str()) == 0 &&
            strcmp(each->getPassword().c_str(), password.c_str()) == 0) {
            return each->getPerson();
        }
    }

    return nullptr;
}

// Επιστρέφει λίστα καθηγητών του τμήματος οι οποίοι διδάσκουν μαθήματα και σε άλλο τμήμα.
// FIXME 02: global prof
list<Professor *> EClass::globalProfessorsList() {
    list<Professor *> listOfGlobalProfessors;

    Professor *professor;
    for (Person *const &each: studentsAndProfessorsList) {
        professor = dynamic_cast<Professor *>(each);
        if (professor != nullptr)
            listOfGlobalProfessors.push_back(professor);
    }

    return listOfGlobalProfessors;
}

// PART B

// (iv) Να υλοποιηθεί μέθοδος printFacultyData() στην κλάση EClass η οποία θα τυπώνει τα στοιχεία των μελών του τμήματος.
void EClass::printFacultyData() {

    Professor *professor;
    Student *student;

    for (Person *const &each: studentsAndProfessorsList) {

        // print professor
        professor = dynamic_cast<Professor *>(each);
        if (professor != nullptr) {
            // FIXME 01 print()
            // professor.print();
        }

        // print student
        student = dynamic_cast<Student *>(each);
        if (student != nullptr) {
            // FIXME 01 print()
            // professor.print();
        }

    }

}


