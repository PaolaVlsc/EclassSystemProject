//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_PROFESSOR_H
#define ECLASSSYSTEMPROJECT_PROFESSOR_H


#include "Person.h"

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

    // FIXME 01: virtual print()
};


#endif //ECLASSSYSTEMPROJECT_PROFESSOR_H
