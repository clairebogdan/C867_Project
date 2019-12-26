#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include <string>
#include "student.h"
using namespace std;


class NetworkStudent : public Student {
public:
    //constructor
    NetworkStudent();
    NetworkStudent(
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
    ~NetworkStudent();            
};

#endif

