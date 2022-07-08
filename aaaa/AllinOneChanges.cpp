#include <iostream>
#include <list>
#include <string.h>
#include <string>
#include <typeinfo>
#include <fstream>
#include <stdio.h>

using namespace std;

//===================================================
//Classes
//===================================================
class Course
{
    string ID;
    string Name;
    int Semester;
public:
    Course (string, string, int);
    Course (const Course &);
    string getID ();
    string getName ();
    int getSemester ();
};

class Person 
{
protected:
    char *Surname;
    char *Firstname;
    string Email;
    list <Course *> Courses;
    virtual ~Person();
public:
    Person (char *, char *, string);
    Person (const Person &);
    void AddCourse (Course *);
    virtual void Print (ostream &) = 0;
    void ShowCourses (ostream &);
    bool HasCourse (Course *);
    int getCoursesSize();
};

class Prof: public Person
{
    int ID;
    string Spec;
public:
    Prof (int, char *, char *, string, string);
    void Print (ostream &);  
	Prof& operator=(const Prof&);  
};

class Stud: public Person
{
    int AM;
    int Semester;
public:
    Stud (int, char *, char *, int, string);
    void Print (ostream &);
    int getSemester ();
    void setSemester (int);
    Stud& operator=(const Stud&);
};

class User
{
    string UName;
    string UPass;
    Person *CUser;
public:
    User (string, string, Person *);
    string getUName ();
    string getUPass ();
    Person *getCUser ();
};

class Eclass
{
    list <Person *> Persons;
    list <User *> Users;
public:
    void AddPerson (Person *);
    void AddUser (User *);
    void printStudentList (Course *, ostream &);
    void listStudents (ostream &);
    void listFaculty (ostream &);
    void operator++ (int);
    Person *listData (string, string);
    void LoadUsers (char *);
};

//===================================================
//Course
//===================================================
Course::Course (string I, string N, int S)
{
    ID = I;
    Name = N;
    Semester = S;
}

Course::Course (const Course &x)
{
    ID = x.ID;
    Name = x.Name;
    Semester = x.Semester;
}

string Course::getID ()
{
    return ID;
}

string Course::getName ()
{
    return Name;
}

int Course::getSemester ()
{
    return Semester;
}

//===================================================
//Person
//===================================================
Person::Person (char *S, char *F, string E)
{
    Surname = new char[strlen (S) + 1];
    strcpy (Surname, S);
    Firstname = new char[strlen (F) + 1];
    strcpy (Firstname, F);
    Email = E;
}

Person::Person (const Person &x)
{
    Surname = new char[strlen (x.Surname) + 1];
    strcpy (Surname, x.Surname);
    Firstname = new char[strlen (x.Firstname) + 1];
    strcpy (Firstname, x.Firstname);
    Email = x.Email;
    Courses = x.Courses;
}


Stud& Stud::operator=(const Stud &copy) {

    if (this == &copy)
        return *this;       
        
    this->AM = copy.AM;
    this->Semester = copy.Semester;
    this->Surname = new char[strlen (copy.Surname) + 1];
    strcpy (this->Surname,copy.Surname);
    this->Firstname = new char[strlen (copy.Firstname) + 1];
    strcpy (this->Firstname, copy.Firstname);
    Email = copy.Email;
    Courses = copy.Courses;

    return *this;
}  

Person::~Person ()
{
    delete[] Surname;
    delete[] Firstname;
}

void Person::AddCourse (Course * C)
{
    Courses.push_back (C);
}

void Person::ShowCourses (ostream &os)
{
    list <Course *>::iterator it;
    for (it = Courses.begin (); it != Courses.end (); it++)
        os << "\t" << (*it)->getID () << "   " << (*it)->getName () << "   " << (*it)->getSemester () << endl;
}

bool Person::HasCourse (Course *C)
{
    list <Course *>::iterator it;
    for (it = Courses.begin (); it != Courses.end (); it++)
        if (*it == C)
            return true;
    return false;
}

int Person::getCoursesSize()
{
	return Courses.size();
}


//===================================================
//Professor
//===================================================
Prof::Prof (int I, char *S, char *F, string E, string Sp): Person (S, F, E)
{
    ID = I;
    Spec = Sp;
}

void Prof::Print (ostream &cha)
{
    cha << "ID..................: " << ID << endl;
    cha << "Surname.............: " << Surname << endl;
    cha << "Firstname...........: " << Firstname << endl;
    cha << "EMail...............: " << Email << endl;
    cha << "Speciality..........: " << Spec << endl;
    ShowCourses (cha);
    cha << "------------------------------------------------------" << endl;
}
Prof& Prof::operator=(const Prof &copy) {

    if (this == &copy)
        return *this;       
        
    this->ID = copy.ID;
    this->Spec = copy.Spec;
    this->Surname = new char[strlen (copy.Surname) + 1];
    strcpy (this->Surname,copy.Surname);
    this->Firstname = new char[strlen (copy.Firstname) + 1];
    strcpy (this->Firstname, copy.Firstname);
    Email = copy.Email;
    Courses = copy.Courses;

    return *this;
}

//===================================================
//Student
//===================================================
Stud::Stud (int A, char *S, char *F, int Se, string E): Person (S, F, E)
{
    AM = A;
    Semester = Se;
}

void Stud::Print (ostream &cha)
{
    cha << "ID..................: " << AM << endl;
    cha << "Surname.............: " << Surname << endl;
    cha << "Firstname...........: " << Firstname << endl;
    cha << "EMail...............: " << Email << endl;
    cha << "Semester............: " << Semester << endl;
    ShowCourses (cha);
    cha << "------------------------------------------------------" << endl;
}

int Stud::getSemester ()
{
    return Semester;
}

void Stud::setSemester (int s)
{
    Semester = s;
}



//===================================================
//User
//===================================================
User::User (string N, string P, Person *U): UName (N), UPass(P), CUser (U)
{

}

string User::getUName ()
{
    return UName;
}

string User::getUPass ()
{
    return UPass;
}

Person * User::getCUser ()
{
    return CUser;
}

//===================================================
//Eclass
//===================================================
void Eclass::AddPerson (Person *P)
{
    Persons.push_back (P);
}

void Eclass::AddUser (User *U)
{
    Users.push_back (U);
}

void Eclass::printStudentList (Course *C, ostream &x)
{
    Stud *sp;
    list<Person *>::iterator it;
    for (it = Persons.begin (); it != Persons.end (); it++)
        if ((*it)->HasCourse (C))
        {
            sp = dynamic_cast <Stud *> (*it); //για να αφορα καθηγητη Prof όπου Stud
            //sp = (Stud *) (*it);                                  //check this out
            if (sp)
            {
				cout<<"!!! EIMAI STUD ΚΙ ΧΩ ΤΟ ΜΑΘΗΜΑ ΠΟΥ ΖΗΤΗΣΕΣ !!!"<<endl;
                sp->Print (x); }
                
        }
}



void Eclass::listFaculty (ostream &x)
{
    list<Person *>::iterator it;
    for (it = Persons.begin (); it != Persons.end (); it++)
    {
        if (typeid (*(*it)) == typeid (Prof)) 
           {
           	
           	cout<<"!!! EIMAI FACULTY ΠΡΟΣΩΠΙΚΟ !!!"<<endl;
           	(*it)->Print (x);
           	
			}
    }   
}

void Eclass::listStudents (ostream &x)
{
    list<Person *>::iterator it;
    for (it = Persons.begin (); it != Persons.end (); it++)
    {
        if (typeid (*(*it)) == typeid (Stud)) 
           {
           	
           if( (*it)->getCoursesSize() !=0 )
           	(*it)->Print (x);
           	
			}
    }   
}

void Eclass::operator++ (int)
{
    Stud *sp;
    list<Person *>::iterator it;
    for (it = Persons.begin (); it != Persons.end (); it++)
    {
        sp = dynamic_cast <Stud *> (*it);
        if (sp)
            sp->setSemester (sp->getSemester () + 1);
    }
}
Person *Eclass::listData (string L, string P)
{
    list<User *>::iterator it;
    for (it = Users.begin (); it != Users.end (); it++)
        if ((*it)->getUName () == L && (*it)->getUPass () == P)
            return (*it)->getCUser ();                                //Is that absolutely correct?
    return NULL;
}

void Eclass::LoadUsers (char *Fn)
{
    int C;
    char Ln[20];
    char Pass[20];
    char Line[100];
    ifstream inp (Fn, ios::in);
    do
    {
        inp.getline (Line, 100);
        if (!inp.eof () && strlen (Line) > 2)
        {
            cout << Line << endl;
            sscanf (Line, "%d,%[^','],%s", &C, Ln, Pass);
            cout << C << " " << Ln << " " << Pass << endl << endl;
            //Χειρισμός σύμφωνα με όσα ειπώθηκαν στο φροντιστήριο
        }
    
    }
    while (!inp.eof ());
    inp.close ();
}
        

//===================================================
//Main Program
//===================================================

ostream & operator<< (ostream &out, Eclass cl)
{
    cl.listStudents (out);
    
}

int main (int argc, char **argv)
{	system ("chcp 1253 > nul");
    Eclass Ecl;
    // Create Data and insert them in eclass
    Course *C1 = new Course ("N1-2020", "Αντικειμενοστραφής Προγραμματισμός", 2);
    Course *C2 = new Course ("N1-3030", "Δίκτυα", 3);
    Course *C3 = new Course ("N1-4040", "Γραφικά", 4); 
    Stud *S1 = new Stud (100, "Ιωάννου", "Ιωάννης", 1, (const char *)"cs100@teiath.gr");
    Stud *S2 = new Stud (200, "Αντωνίου", "Αντώνιος", 3, "cs200@teiath.gr");
    Stud *S3 = new Stud (300, "Κούτσουρο", "Απελέκητο", 3, "cs300@teiath.gr");
    Prof *P1 = new Prof (80, "Γεωργίου", "Γεωργία", "geor@teiath.gr", "Τεχνητή Νοημοσύνη");
    Prof *P2 = new Prof (90, "Καινουριος", "Καινουριου", "kain@teiath.gr", "Σπεσιαλ");
    S1->AddCourse (C1);
    S1->AddCourse (C2);
    S2->AddCourse (C1);
    S2->AddCourse (C3);
   // S3->AddCourse (C1);
    P1->AddCourse (C2);
    P1->AddCourse (C3);
    P2->AddCourse(C1); 
    User *U1 = new User ("Log1", "Pass1", S1);
    User *U2 = new User ("Log2", "Pass2", S2);
    User *U3 = new User ("Log3", "Pass3", P1);
   // User *U4 = new User ("Log4", "Pass4", S3);
    Ecl.AddPerson (S1);
    Ecl.AddPerson (S2);
    Ecl.AddPerson (P1);
    Ecl.AddPerson (P2);
  //  Ecl.AddPerson (S3);
    Ecl.AddUser (U1);
    Ecl.AddUser (U2);
    Ecl.AddUser (U3);
    Ecl.AddPerson (P2);
  //  Ecl.AddUser (U4);
    // Students that study a course
    Ecl.printStudentList (C2, cout);
    cout<<"#ΚΛΗΘΗΚΕ Η STUDENT 2 COURSE#"<<endl;
    cout << "=====================================================================" << endl << endl; 
    // Login
    Person *p = Ecl.listData ("Log3", "Pass3");
    if (p)
       {
       	cout<<"#ΥΠΑΡΧΕΙ PERSON ME Log3 Pass3 (LISTDATA)#"<<endl;
       	p->Print (cout);
		} 
    else
        cout << "No such user..." << endl;
        
    Person *pp = Ecl.listData ("Log2", "Pass2");
    if (pp)
       {
       	cout<<"#ΥΠΑΡΧΕΙ PERSON ME Log2 Pass2 (LISTDATA)#"<<endl;
       	pp->Print (cout);
		} 
    else
        cout << "No such user..." << endl;    
        
        
    cout << "=====================================================================" << endl << endl; 
    // List of Students with <<
    cout << Ecl;
    cout << "=====================================================================" << endl << endl; 
    //Semester ++
    Ecl++;
    cout << Ecl;
    cout<<"#ΤΥΠΩΘΗΚΕ ΤΟ ECL ΜΕΤΑ ΤΗΝ ΑΛΛΑΓΗ ΕΞΑΜΗΝΟΥ + 1 #"<<endl;
    cout << "=====================================================================" << endl << endl; 
    //Load from File
    cout<<"# ΠΑΡΑΚΑΤΩ Ο,ΤΙ ΕΧΕΙ ΤΟ USERS TXT #"<<endl;
    Ecl.LoadUsers ("Users.txt");
    cout << "=====================================================================" << endl << endl; 
    Ecl.listFaculty(cout);
    cout<<"# ΠΑΡΑΠΑΝΩ ΟΙ FACULTY  #"<<endl;
    cout << "=====================================================================" << endl << endl; 
	cout << "=====================================================================" << endl << endl;    
	*S1=*S2;
	cout << Ecl; 
	cout << "=====================================================================" << endl << endl;  
	S2->AddCourse(C2);
	cout << Ecl;
	cout << "=====================================================================" << endl << endl;
	*P1=*P2;
	Ecl.listFaculty(cout);
    //ta delete
    delete S1;
    delete S2;
    delete S3;
    delete P1;
    delete U1;
    delete U2;
    delete U3;
    delete C1;
    delete C2;
    delete C3; 
    
    
    
    
    return 0;
}

                         
    


    
