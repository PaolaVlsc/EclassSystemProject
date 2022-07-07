#include <iostream>
#include "Course.h"
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


    return 0;
}
