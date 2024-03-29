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
using std::ostream;

class Person {
private:

    string code;
    char *lastName;
    char *firstName;
    string email;
    list<Course *> coursesList;
public:
    // constructor
    Person(const string &, const char *, const char *, const string &);
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

    virtual void print(ostream &) const = 0;
    void addCourse(Course &);

    // Έλεγχος αν έχει αυτό το μάθημα
    bool hasCourse(Course &);
};

ostream &operator<<(ostream &, const list<Course *> &);

#endif //ECLASSSYSTEMPROJECT_PERSON_H
