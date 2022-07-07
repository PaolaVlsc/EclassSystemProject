//
// Created by Velasco on 7/7/2022.
//

#include "Person.h"

Person::Person(const string &code, char *lastName, char *firstName, const string &email,
               const list<Course *> &coursesList) : code(code), lastName(lastName), firstName(firstName), email(email),
                                                    coursesList(coursesList) {}
