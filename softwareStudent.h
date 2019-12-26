#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include <string>
#include "student.h"
using namespace std;


class SoftwareStudent : public Student {
public:
    //constructor
    SoftwareStudent();
    SoftwareStudent(
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
    ~SoftwareStudent();            
};

#endif


