#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "User.h"
#include "EClass.h"
#include<list>
#include <fstream>
using namespace std;

// φοιτητές που παρακολουθούν ένα τουλάχιστον μάθημα
list<Student *> activeStudents();

// Υπερφορτώστε τον τελεστή << : να τυπώνει τα στοιχεία των φοιτητών που παρακολουθούν μαθήματα στο τμήμα.
ostream &operator<<(ostream &stream, const EClass &);

// Να υλοποιηθεί μέθοδος η οποία θα φορτώνει από αρχείο κειμένου τα ονόματα χρήστη και τα συνθηματικά των μελών του τμήματος.
// Το αρχείο περιέχει τα στοιχεία όλων των μελών του ιδρύματος.
// Κάθε γραμμή περιέχει τα στοιχεία ενός μέλους  και έχει την εξής γραμμογράφηση:
void readFromFileUsers(const string &);

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

    string fileName = "users.txt";
    readFromFileUsers(fileName);

    return 0;
}



void readFromFileUsers(const string &fileName)
{
    // Δημιουργία stream
    ifstream fileInput;

    // Άνοιγμα αρχείου
    fileInput.open(fileName.c_str());

    // Έλεγχος ενέργειας
    if (fileInput.is_open() == false) {
        cout << "Σφάλμα κατά το άνοιγμα αρχείου για διάβασμα μαθήματα σχολής \n";
        throw -1;
    }

    int code;
    char username[20];
    char password[100];
    string line;

    cout << endl << "Users from file" << endl;
    // read line
    while (1) {
        // diavasma grammhs
        getline(fileInput, line);
        // cout << line << endl;
        if (!fileInput)
            break; // An exei ftasei sto telos tou arxeiou OR egine kapoio sfalma

        sscanf(line.c_str(), "%d,%[^,],%s\n", &code, username ,password);
        cout << code << " " << username << " " << password << endl;

    }

    fileInput.close();
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

