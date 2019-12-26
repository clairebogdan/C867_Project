#include <cstdlib>
#include <iostream>
#include <string>
#include "networkStudent.h"
using namespace std;

//constructor
NetworkStudent::NetworkStudent():Student(){
    degreeType = NETWORKING;
}
NetworkStudent::NetworkStudent(string idNum, string fName, string lName, string eAddress, int ageNum, int days[], Degree dtype)
    :Student(idNum, fName, lName, eAddress, ageNum, days){
    degreeType = NETWORKING;
}

//accessor (getter)
Degree NetworkStudent::getDegreeProgram(){
    return NETWORKING;
}

//print
void NetworkStudent::print(){
    this->Student::print();
    cout << "Degree Type: Networking" << endl;
}

//destructor
NetworkStudent::~NetworkStudent(){
    Student::~Student();
}



