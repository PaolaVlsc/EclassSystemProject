#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "User.h"
#include "EClass.h"
#include<list>

using namespace std;

// φοιτητές που παρακολουθούν ένα τουλάχιστον μάθημα
list<Student *> activeStudents();

// Υπερφορτώστε τον τελεστή << : να τυπώνει τα στοιχεία των φοιτητών που παρακολουθούν μαθήματα στο τμήμα.
ostream &operator<<(ostream &stream, const EClass &);

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

list<Student *> activeStudents(const EClass &eclass) {
    list<Student *> listActiveStudents;
    Student *student;

    for (Person *const &each: eclass.getStudentsAndProfessorsList()) {
        student = dynamic_cast<Student *>(each);
        if (student != nullptr) {
            // check if it has courses
            if (student->getCoursesList().empty() != 0) {
                listActiveStudents.push_back(student);
            }
        }
    }
    return listActiveStudents;
}

ostream &operator<<(ostream &stream, const EClass &eclass) {
    list<Student *> listActiveStudents = activeStudents(eclass);
    for (Student *&each: listActiveStudents) {
        // FIXME 01: print()
        //  each->print();
    }
    return stream;
}


// (ix) Υπερφορτώστε τον τελεστή μετα αύξησης ++ ώστε κατά την εφαρμογή του να αυξάνεται κατά ένα το εξάμηνο όλων των φοιτητών του τμήματος.
// operator ++ (r--)
EClass operator++(EClass &eclass) {
    EClass temp;
    temp = eclass;

    // list of students in Eclass ( active )
    list<Student *> listActiveStudents = activeStudents(eclass);
    for (Student *&each: listActiveStudents) {
        each->setSemester(each->getSemester() + 1);
    }

    return temp;
}