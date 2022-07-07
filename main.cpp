#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "User.h"
#include<list>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;


    list<Course *> coursesList;
    coursesList.push_back(new Course("ICE01", "C++", 2));
    coursesList.push_back(new Course("ICE02", "JAVA", 3));
    coursesList.push_back(new Course("ICE03", "Python", 6));
    coursesList.push_back(new Course("ICE04", "C#", 10));
    coursesList.push_back(new Course("ICE05", "Maths", 1));

//    Person person01("cs161020", "Velasco", "Paola", "cs161020@uniwa.gr", coursesList);
//    cout << person01.getFirstName();

    Student student01("cs161020", "Velasco", "Paola", 12, "cs161020@uniwa.gr", coursesList);
    cout << student01.getFirstName();

//    Professor professor01("cs161020", "Velasco", "Paola", "nai", "cs161020@uniwa.gr", coursesList);
//    cout << professor01.getSpeciality();

    User user01("Log01", "1234", &student01);
    cout << user01.getPerson()->getCode();


    return 0;
}
