//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_PERSON_H
#define ECLASSSYSTEMPROJECT_PERSON_H

#include <list>
#include <string>
#include "Course.h"

using std::list;
using std::string;

class Person {
private:

    string code;
    char *lastName;
    char *firstName;
    string email;
    list<Course *> coursesList;
public:
    // constructor
    Person(const string &, const char *, const char *, const string &, const list<Course *> &);

    // copy constructor
    Person(const Person &);

    // destructor
    virtual ~Person();

    // setters
    void setCode(const string &code);

    void setLastName(const char *lastName);

    void setFirstName(const char *firstName);

    void setEmail(const string &email);

    void setCoursesList(const list<Course *> &coursesList);

    // getters
    const string &getCode() const;

    char *getLastName() const;

    char *getFirstName() const;

    const string &getEmail() const;

    const list<Course *> &getCoursesList() const;

    // FIXME 01: pure virtual
    //virtual void print(ostream &) const = 0;

    // Να υπερφορτωθεί ο τελεστής = (assignment operator)ώστε να πραγματοποιείται σωστά η λειτουργία ανάθεσης.
    //template <typename T> T& operator=(const T &) ;

    // Έλεγχος αν έχει αυτό το μάθημα
    bool hasCourse(Course &);
};


#endif //ECLASSSYSTEMPROJECT_PERSON_H
