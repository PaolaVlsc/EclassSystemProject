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
// printStudentList
list<Student *> activeStudents(const EClass &);

// Υπερφορτώστε τον τελεστή << : να τυπώνει τα στοιχεία των φοιτητών που παρακολουθούν μαθήματα στο τμήμα.
ostream &operator<<(ostream &stream, const EClass &);
//EClass operator++(EClass &eclass);

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
    student01.print(cout);

    Professor professor01("cs161020", "Velasco", "Paola", "nai", "cs161020@uniwa.gr", coursesList);
    cout << professor01.getSpeciality();
    professor01.print(cout);


    User user01("Log01", "1234", &student01);
    cout << user01.getPerson()->getCode();

    string fileName = "users.txt";
    try {
        readFromFileUsers(fileName);
    } catch (int code) {
        if (code == -1) {
            cout << endl << "Σφάλμα κατά το άνοιγμα αρχείου για διάβασμα users \n";
            exit(EXIT_FAILURE);
        }
    }



//    Student student02("cs161020", "ad", "a", 12, "cs161d0@uniwa.gr", coursesList);
//    cout << student02.getFirstName();
//    student02.print(cout);
//    student02 = student01;
//    student02.print(cout);
//
//    Course *C1 = new Course ("N1-2020", "Αντικειμενοστραφής Προγραμματισμός", 2);
//    student01.addCourse(*C1);
//    student01.print(cout);
//
//    Professor professor02("cs161020", "3", "43", "ddd", "cs1fs61020@uniwa.gr", coursesList);
//    cout << professor02.getSpeciality();
//    professor02.print(cout);
//
//    professor02 = professor01;
//    professor02.print(cout);
//
//    professor01.addCourse(*C1);
//    professor01.print(cout);



    ////////////////////////

    Course *C1 = new Course("N1-2020", "Αντικειμενοστραφής Προγραμματισμός", 2);
    Course *C2 = new Course("N1-3030", "Δίκτυα", 3);
    Course *C3 = new Course("N1-4040", "Γραφικά", 4);

    Student *S1 = new Student("100", "Ιωάννου", "Ιωάννης", 1, "cs100@teiath.gr");
    Student *S2 = new Student("200", "Αντωνίου", "Αντώνιος", 3, "cs200@teiath.gr");
    Professor *P1 = new Professor("80", "Γεωργίου", "Γεωργία", "geor@teiath.gr", "Τεχνητή Νοημοσύνη");

    S1->addCourse(*C1);
    S1->addCourse(*C2);
    S2->addCourse(*C1);
    S2->addCourse(*C3);
    P1->addCourse(*C2);
    P1->addCourse(*C3);

    User *U1 = new User("Log1", "Pass1", S1);
    User *U2 = new User("Log2", "Pass2", S2);
    User *U3 = new User("Log3", "Pass3", P1);

    EClass eClass;
    eClass.addPerson(*S1);
    eClass.addPerson(*S2);
    eClass.addPerson(*P1);
    eClass.addUser(*U1);
    eClass.addUser(*U2);
    eClass.addUser(*U3);

    // Students that study a course
    list<Student *> studentsOfACourse = eClass.listOfRegisteredStudentsOnCourse(*C2);
    for (Student *&each: studentsOfACourse) {
        each->print(cout);
    }

    // Login
    cout << "Login" << endl;
    Person *p = eClass.listData("Log3", "Pass3");
    if (p)
        p->print(cout);
    else
        cout << "No such user..." << endl;


    // printFacultyData
    eClass.printFacultyData();

    // printFacultyData
    cout << "OKAAHSDIASHJDKAJDKASDA" << endl;
    for (Student *&each: activeStudents(eClass)) {
        each->print(cout);
    }

    // print out active students
    cout << "5555555" << endl;
    cout << eClass;

    // ++
    cout << "++" << endl;
    eClass++;
    cout << eClass;

    return 0;
}


void readFromFileUsers(const string &fileName) {
    // Δημιουργία stream
    ifstream fileInput;

    // Άνοιγμα αρχείου
    fileInput.open(fileName.c_str());

    // Έλεγχος ενέργειας
    if (fileInput.is_open() == false) {
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

        sscanf(line.c_str(), "%d,%[^,],%s\n", &code, username, password);
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
            if (student->getCoursesList().size() != 0) {
                listActiveStudents.push_back(student);
                //student->print(cout);
            }
        }
    }
    return listActiveStudents;
}

ostream &operator<<(ostream &stream, const EClass &eclass) {
    list<Student *> listActiveStudents = activeStudents(eclass);
    for (Student *&each: listActiveStudents) {
        each->print(stream);
    }
    return stream;
}


//// (ix) Υπερφορτώστε τον τελεστή μετα αύξησης ++ ώστε κατά την εφαρμογή του να αυξάνεται κατά ένα το εξάμηνο όλων των φοιτητών του τμήματος.
//// operator ++ (r--)
//EClass operator++(EClass &eclass) {
//    EClass temp;
//    temp = eclass;
//
//    // list of students in Eclass ( active )
//    list<Student *> listActiveStudents = activeStudents(eclass);
//    for (Student *&each: listActiveStudents) {
//        each->setSemester(each->getSemester() + 1);
//    }
//
//    return temp;
//}

