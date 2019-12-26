#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include <iostream>
#include "student.h"
using namespace std;


class Roster {
public:    
    //constructor
    Roster();
    Roster(int capacity);
    
    //main functions
    void    parse                    (string data);
    void    add                      (string data0, 
                                      string data1, 
                                      string data2, 
                                      string data3, 
                                      int data4, 
                                      int data5, 
                                      int data6, 
                                      int data7, 
                                      string data8);
    void    remove                   (string studentID);
    void    printInvalidEmails();
    void    printAverageDaysInCourse (string studentID);
    void    printByDegreeProgram     (int degreeProgram);
    void    printAll();
    
    //classRosterArray pointer
    Student** classRosterArray;
    
    //destructor
    ~Roster();
    
protected:
    int rosterSize;
    int capacity;
    
};

#endif

