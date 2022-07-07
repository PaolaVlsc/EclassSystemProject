//
// Created by Velasco on 7/7/2022.
//

#ifndef ECLASSSYSTEMPROJECT_USER_H
#define ECLASSSYSTEMPROJECT_USER_H

#include <string>
#include "Person.h"

using std::string;

class User {
private:
    string username;
    string password;
    Person *person;
public:

    // constructor
    User(const string &, const string &, Person *);

    // copy constructor
    User(const User&);

    // destructor
    virtual ~User();

    // setters
    void setUsername(const string &username);
    void setPassword(const string &password);
    void setPerson(Person *person);

    // getters
    const string &getUsername() const;
    const string &getPassword() const;
    Person *getPerson() const;


};


#endif //ECLASSSYSTEMPROJECT_USER_H
