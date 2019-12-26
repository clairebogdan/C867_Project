#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

int i = 0;

//constructor definitions
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i =0; i < 3; i++) {this->daysToComplete[i] = 0;}
}

Student::Student(string idNum, string fName, string lName, string eAddress, int ageNum, int days[]){
    this->studentID = idNum;
    this->firstName = fName;
    this->lastName = lName;
    this->emailAddress = eAddress;
    this->age = ageNum;
    for (int i =0; i < 3; i++){
        this->daysToComplete[i] = days[i];
    }
}


//mutator (setter) definitions
void Student::setStudentID(string idNum){
    this->studentID = idNum;
}
void Student::setFirstName(string fName){
    this->firstName = fName;
}
void Student::setLastName(string lName){
    this->lastName = lName;
}
void Student::setEmailAddress(string eAddress){
    this->emailAddress = eAddress;
}
void Student::setAge(int ageNum){
    this->age = ageNum;
}
void Student::setDaysToComplete(int days[]){
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = days[i];
    }
}


//accessor (getter) definitions
string Student::getStudentID(){
    return studentID;
}
string Student::getFirstName(){
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmailAddress(){
    return emailAddress;
}
int Student::getAge(){
    return age;
}
int* Student::getDaysToComplete(){
    return daysToComplete;
}


//virtual print
void Student::print(){
    cout << getStudentID() << "\t"
         << "First Name: " << getFirstName() << "\t"
         << "Last Name: " << getLastName() << "\t"
         << "Age: " << getAge() << "\t"
         << "daysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << "\t";
}

//destructor definition
Student::~Student(){}
