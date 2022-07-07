//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_ECLASS_H
#define ECLASSSYSTEMPROJECT_ECLASS_H


#include "Person.h"
#include "User.h"
#include "Student.h"
#include "Professor.h"

class EClass {
private:

    // Διατηρεί ενιαία λίστα με τους φοιτητές που παρακολουθούν τα μαθήματα στο τμήμα και τους καθηγητές που διδάσκουν σε αυτό
    list<Person *> studentsAndProfessorsList;

    // Διατηρεί λίστα με τα ονόματα χρήστη και τα συνθηματικά των χρηστών του συστήματος.
    list<User *> usersList;

public:
    // constructor
    // use default

    // copy constructor
    // use default

    // destructor
    // use default


    // getters
    const list<Person *> &getStudentsAndProfessorsList() const;

    const list<User *> &getUsersList() const;

    // setters
    void setStudentsAndProfessorsList(const list<Person *> &studentsAndProfessorsList);

    void setUsersList(const list<User *> &usersList);

    // Δημιουργεί καταστάσεις με τους φοιτητές που παρακολουθούν ένα μάθημα
    list<Student *> listOfRegisteredStudentsOnCourse(Course &);

    // Δέχεται το όνομα και το συνθηματικό ενός χρήστη του συστήματος και
    // επιστρέφει τα στοιχεία του χρήστη στον οποίο αντιστοιχούν (αν είναι σωστά).
    Person *listData(const string &username, const string &password);

    // Επιστρέφει λίστα καθηγητών του τμήματος οι οποίοι διδάσκουν μαθήματα και σε άλλο τμήμα.
    list<Professor *> globalProfessorsList();

    // PART B

    // (iv) Να υλοποιηθεί μέθοδος printFacultyData() στην κλάση EClass η οποία θα τυπώνει τα στοιχεία των μελών του τμήματος.
    void printFacultyData();



};


#endif //ECLASSSYSTEMPROJECT_ECLASS_H
