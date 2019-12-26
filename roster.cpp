#include <iostream>
#include <string>
#include "roster.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using namespace std;


int main(){

//enter given data
const string studentData[] =
 {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Claire,Bogdan,cbogdan@wgu.edu,24,7,20,10,SOFTWARE"
};

//parse data (see parse function)
int numStudents = 5;
Roster* classRoster = new Roster(numStudents);
for (int i = 0; i < numStudents; i++){
    classRoster->parse(studentData[i]);
}


/////////////////////////
//OUTPUT STATEMENTS BELOW
/////////////////////////


//print personal information
cout << "C867: Scripting and Programming Applications" << endl
     << "Programming language: C++" << endl
     << "Student ID: 001210883" << endl
     << "Name: Claire Bogdan" << endl 
     << "---------------------------------------------------" << endl;

//print project tasks
classRoster->printAll();
cout << "---------------------------------------------------" << endl;


classRoster->printInvalidEmails();
cout << "---------------------------------------------------" << endl;


cout << "AVERAGE DAYS TO COMPLETE A COURSE:" << endl;
for (int i = 0; i < numStudents; i++){
    classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
}
cout << "---------------------------------------------------" << endl;


classRoster->printByDegreeProgram(SOFTWARE);
cout << "---------------------------------------------------" << endl;


classRoster->remove("A3");
        cout << "Printing updated list..." << endl << endl;
        classRoster->printAll();
cout << "---------------------------------------------------" << endl;


classRoster->remove("A3");
cout << "---------------------------------------------------" << endl;


cout << "End of project." << endl;
return 0;
}


////////////////////////////
//FUNCTION DEFINITIONS BELOW
////////////////////////////


//empty constructor definition
Roster::Roster(){
    this->capacity = 0;
    this->rosterSize = 0;
    this->classRosterArray = nullptr;
}

//constructor definition
Roster::Roster(int capacity){
    this->capacity = capacity;
    this->rosterSize = 0;
    this->classRosterArray = new Student*[capacity];
}

//main function definitions
void Roster::parse(string data){
    //data0 = Student ID
    int rhs = data.find(",");
    string data0 = data.substr(0,rhs);
    
    //data1 = First name
    int lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string data1 = data.substr(lhs, rhs - lhs);
    
    //data2 = Last name
    int lhs2 = rhs + 1;
    rhs = data.find(",", lhs2);
    string data2 = data.substr(lhs2, rhs - lhs2);
    
    //data3 = Email
    int lhs3 = rhs + 1;
    rhs = data.find(",", lhs3);
    string data3 = data.substr(lhs3, rhs - lhs3);
    
    //data4 = Age
    int lhs4 = rhs + 1;
    rhs = data.find(",", lhs4);
    int data4 = stoi(data.substr(lhs4, rhs - lhs4));
    
    //data5 = Days entry 1
    int lhs5 = rhs + 1;
    rhs = data.find(",", lhs5);
    int data5 = stoi(data.substr(lhs5, rhs - lhs5));
    
    //data6 = Days entry 2
    int lhs6 = rhs + 1;
    rhs = data.find(",", lhs6);
    int data6 = stoi(data.substr(lhs6, rhs - lhs6));
    
    //data7 = Days entry 3
    int lhs7 = rhs + 1;
    rhs = data.find(",", lhs7);
    int data7 = stoi(data.substr(lhs7, rhs - lhs7));
    
    //data8 = Degree
    int lhs8 = rhs + 1;
    rhs = data.find(",", lhs8);
    string data8 = data.substr(lhs8, rhs - lhs8);
    
    //add parsed data to roster
    add(data0, data1, data2, data3, data4, data5, data6, data7, data8);
}

void Roster::add(string data0, string data1, string data2, string data3, int data4, int data5, int data6, int data7, string data8){
    //input data5-data7 to days array
    int days[3] = {data5, data6, data7};
    
    //convert data8 to enum Degree
    Degree theDegree;
        if (data8 == "SECURITY") {
            theDegree = SECURITY;
        }
        else if (data8 == "NETWORK") {
            theDegree = NETWORKING;
        }
        else if (data8 == "SOFTWARE") {
            theDegree = SOFTWARE;
    }
    
    //add new objects based on theDegree
    switch (theDegree) {
        case SECURITY:   
            classRosterArray[rosterSize] = new SecurityStudent(data0, data1, data2, data3, data4, days, theDegree);
            rosterSize++;
            break;
    
        case NETWORKING:   
            classRosterArray[rosterSize] = new NetworkStudent(data0, data1, data2, data3, data4, days, theDegree);
            rosterSize++;
            break;
    
        case SOFTWARE:   
            classRosterArray[rosterSize] = new SoftwareStudent(data0, data1, data2, data3, data4, days, theDegree);
            rosterSize++;
            break;
    }
}

void Roster::printAll(){
   cout << "ALL STUDENTS:" << endl;
   for (int i = 0; i < rosterSize; i++) {
       this->classRosterArray[i]->print();
    }
}
   
void Roster::remove(string studentID){
    for (int i = 0; i <= rosterSize; i++) {
        if (this->classRosterArray[i] == nullptr){
            cout << "Error: Student " << studentID << " does not exist." << endl;
        }
        else if (this->classRosterArray[i]->getStudentID().compare(studentID) == 0){
            classRosterArray[i] = nullptr;
            cout << "REMOVING " << studentID << "... ";
            cout << studentID << " was removed." << endl;
            
            //update roster
            rosterSize--;
                for (i = i; i <= rosterSize; i++){
                    classRosterArray[i] = classRosterArray[i+1];
                }
        }
    }
}
        
void Roster::printInvalidEmails(){
    cout << "INVALID EMAILS:" << endl;
    for (int i = 0; i < rosterSize; i++) {
        string checkEmail = this->classRosterArray[i]->getEmailAddress();
        if (checkEmail.find(' ', 0) != string::npos) {
            cout << checkEmail << "\t Error: Email address cannot have spaces." << endl;
        }
        else if (checkEmail.find('.', 0) == string::npos) {
            cout << checkEmail << "\t Error: Email address is missing a period." << endl;
        }
        else if (checkEmail.find('@', 0) == string::npos) {
            cout << checkEmail << "\t Error: Email address is missing the @ symbol." << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    int sum = 0;
    int count = 3;
    for (int i = 0; i < rosterSize; i++){
        if (this->classRosterArray[i]->getStudentID() == studentID){
            int *daysToComp = this->classRosterArray[i]->getDaysToComplete();
                for (int j = 0; j < count; j++){
                    sum += daysToComp[j];
                }
            cout << "Student " << studentID << "'s average number of days to complete 3 courses: " << sum/count << endl;
        }     
    }
}
    
void Roster::printByDegreeProgram(int degreeProgram){
    string degreeName;
    switch (degreeProgram){
        case 0:
            degreeName = "SECURITY";
            break;
        case 1:
            degreeName = "NETWORKING";
            break;
        case 2:
            degreeName = "SOFTWARE";
            break;
    }
    cout << "STUDENTS IN THE " << degreeName << " DEGREE PROGRAM:" << endl;
    for (int i = 0; i < rosterSize; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
}

//destructor definition
Roster::~Roster(){}