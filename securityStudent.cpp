#include <cstdlib>
#include <iostream>
#include <string>
#include "securityStudent.h"
using namespace std;

//constructor
SecurityStudent::SecurityStudent():Student(){
    degreeType = SECURITY;
}
SecurityStudent::SecurityStudent(string idNum, string fName, string lName, string eAddress, int ageNum, int days[], Degree dtype)
    :Student(idNum, fName, lName, eAddress, ageNum, days){
    degreeType = SECURITY;
}

//accessor (getter)
Degree SecurityStudent::getDegreeProgram(){
    return SECURITY;
}

//print
void SecurityStudent::print(){
    this->Student::print();
    cout << "Degree Type: Security" << endl;
}

//destructor
SecurityStudent::~SecurityStudent(){
    Student::~Student();
}