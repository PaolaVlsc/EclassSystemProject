// operator + 
// r1.operator+(r2)
// r4 = r1 + r2 + r3
// αριστερά προς τα δεξιά
Rect Rect::operator+(const Rect &r) const
{
    Rect temp; 
    ...
    return temp;
}


// operator =
// t1 = t2 = t3
// δεξιά προς τα αριστερά
T& T::operator=(const T &t)
{
    if(this == &t)
        return *this; 
    
    delete [] this->s; 
    this->s = new char[strlen....]
    ...
    return *this; 

}

// operator ++ ( ++r)
Rect& Rect::operator++(){
    ...
    return *this; 
}

// operator ++ (r--)
Rect Rect::operator++(int)
{
    Rect temp; 
    temp = *this; 
    ...
    ...
    return temp; 
}

// operator <<  with wtream 
ostream& operator<<(ostream &out, const Rect &rect){
    out << rect.getLength() << ' ' << rect.getHeight() << endl; 
    return out; 
}

// operator >> eg: cin >> r1 >> r2
istream& operator>>(istream &in, Rect &rect)
{
    in >> rect.setLength(); 
    in >> rect.setHeight();

    return in; 
}


// copy constructor called
void funct(Test) {
    cout << "FUNCT00: " << endl;
}

// not called
void funct1(Test &) {
    cout << "FUNCT01: " << endl;
}

// called
Test funct2() {
    Test test;
    cout << "FUNCT02: " << endl;
    return test;
}

// not called -- callee Test& test2 = funct3();
// called -- callee Test test2 = funct3();
Test& funct3() {
    cout << "FUNCT03: " << endl;
    static Test test;
    return test;
}

// delegate constructor
T(int a, int b){

}

T() : T(1, 2)
{

}

T(){
    T(1,2);
}


// Ένας δείκτης σε μια βασική κλάση μπορεί να δείξει σε μια παράγωγη αλλά όχι το αντίθετο