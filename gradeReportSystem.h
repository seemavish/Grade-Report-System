#ifndef RESULT_H_
#define RESULT_H_

#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

class Result
{

public:
    string* name, *studentId;
    float* cgpaScore, *previousTGPA, *currentTGPA;
    int* trimesterCourseCount, *totalCourses;
    vector<string> courses;
    
    Result();
    ~Result();
    bool isValidId(const string studentId);
    void getInfo();
    void getScores();
    void printDetails();
};
 
#endif