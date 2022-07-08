//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_STUDENT_H
#define ECLASSSYSTEMPROJECT_STUDENT_H


#include "Person.h"
#include <iostream>
#include <cstring>

class Student : public Person {
private:
    unsigned int semester;
public:
    // constructor
    Student(const string &, const char *, const char *, unsigned int, const string &);

    Student(const string &, const char *, const char *, unsigned int, const string &,
            const list<Course *> &);

    // copy constructor
    Student(const Student &);

    // destructor
    virtual ~Student();

    // setters and getters
    unsigned int getSemester() const;

    void setSemester(unsigned int semester);

    void print(ostream &) const;

    // operator =
    // t1 = t2 = t3
    // δεξιά προς τα αριστερά
    Student &operator=(const Student &);

};


#endif //ECLASSSYSTEMPROJECT_STUDENT_H
