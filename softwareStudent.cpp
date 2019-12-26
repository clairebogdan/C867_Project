#include <cstdlib>
#include <iostream>
#include <string>
#include "softwareStudent.h"
using namespace std;

//constructor
SoftwareStudent::SoftwareStudent():Student(){
    degreeType = SOFTWARE;
}
SoftwareStudent::SoftwareStudent(string idNum, string fName, string lName, string eAddress, int ageNum, int days[], Degree dtype)
    :Student(idNum, fName, lName, eAddress, ageNum, days){
    degreeType = SOFTWARE;
}

//accessor (getter)
Degree SoftwareStudent::getDegreeProgram(){
    return SOFTWARE;
}

//print
void SoftwareStudent::print(){
    this->Student::print();
    cout << "Degree Type: Software" << endl;
}

//destructor
SoftwareStudent::~SoftwareStudent(){
    Student::~Student();
}