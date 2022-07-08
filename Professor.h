//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_PROFESSOR_H
#define ECLASSSYSTEMPROJECT_PROFESSOR_H


#include "Person.h"
#include <iostream>
#include <cstring>

class Professor : public Person {
    string speciality;
public:
    // constructor
    Professor(const string &, const char *, const char *, const string &, const string &, const list<Course *> &);

    // copy constructor
    Professor(const Professor &);

    // destructor
    virtual ~Professor();

    // setters and getters
    const string &getSpeciality() const;

    void setSpeciality(const string &speciality);

    void print(ostream &) const;
    // operator =
    // t1 = t2 = t3
    // δεξιά προς τα αριστερά
    Professor&  operator=(const Professor &);
};


#endif //ECLASSSYSTEMPROJECT_PROFESSOR_H
