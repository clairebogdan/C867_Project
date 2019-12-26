#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:    
    //constructor
    Student();
    Student(
            string idNum, 
            string fName, 
            string lName, 
            string eAddress, 
            int ageNum, 
            int days[]);
    
    //mutators (setters)
    void           setStudentID      (string idNum);
    void           setFirstName      (string fName);
    void           setLastName       (string lName);
    void           setEmailAddress   (string eAddress);
    void           setAge            (int ageNum);
    void           setDaysToComplete (int days[]);

    //accessors (getters)
    string         getStudentID();
    string         getFirstName();
    string         getLastName();
    string         getEmailAddress();
    int            getAge();
    int*           getDaysToComplete();
    
    //virtuals
    virtual Degree getDegreeProgram() = 0;
    virtual void   print() = 0;
    
    //destructor
    ~Student();
    
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    Degree degreeType;
};

#endif

