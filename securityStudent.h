#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include <string>
#include "student.h"
using namespace std;


class SecurityStudent : public Student {
public:
    //constructor
    SecurityStudent();
    SecurityStudent(
            string idNum, 
            string fName, 
            string lName, 
            string eAddress, 
            int ageNum, 
            int days[], 
            Degree dType);
    
    //accessor (getter)
    Degree getDegreeProgram();
    
    //print
    void print();
    
    //destructor
    ~SecurityStudent();            
};

#endif


