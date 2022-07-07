//
// Created by Velasco on 7/7/2022.
//

#include "User.h"

User::User(const string &username, const string &password, Person *person) : username(username), password(password),
                                                                             person(person) {}

User::User(const User &copy) {

}

User::~User() {

}

void User::setUsername(const string &username) {
    this->username = username;
}

void User::setPassword(const string &password) {
    this->password = password;
}

void User::setPerson(Person *person) {
    this->person = person;
}

const string &User::getUsername() const {
    return this->username;
}

const string &User::getPassword() const {
    return this->password;
}

Person *User::getPerson() const {
    return this->person;
}
