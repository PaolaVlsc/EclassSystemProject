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
    Person(const string &code, char *lastName, char *firstName, const string &email, const list<Course *> &coursesList);
};


#endif //ECLASSSYSTEMPROJECT_PERSON_H
