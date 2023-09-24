#include "gradeReportSystem.h"

#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

Result::Result()
{
    name = new string;
    studentId = new string;
    cgpaScore = new float;
    previousTGPA = new float;
    currentTGPA = new float;
    trimesterCourseCount = new int;
    totalCourses = new int;
}

Result::~Result(){
    delete name;
    delete studentId;
    delete cgpaScore;
    delete previousTGPA;
    delete currentTGPA;
    delete trimesterCourseCount;
    delete totalCourses;
}

bool Result::isValidId(const string studentId)
{
    regex format("SIASUG\\d{2}-\\d{4}");
    return regex_match(studentId, format);
}

void Result::getInfo()
{
    // cin.ignore(); // ignore the newline left in buffer
    cout << "Enter your name: ";
    getline(cin, *name);
    cout << "Enter your student id (SIASUG2*-****): ";
    getline(cin, *studentId);

    // check if id format is correct
    if (!isValidId(*studentId))
    {
        cout << "Incorrect student ID! Try again." << endl;
        return;
    }
    else
    {
        cout << "Enter the number of courses taken in the current trimester: ";
        cin >> *trimesterCourseCount;

        // let's assume minimum courses required are 3 and maximum of 5 courses can be taken in a trimester
        if (*trimesterCourseCount < 3 || *trimesterCourseCount > 5)
        {
            cout << "You do not meet the coure count requirement. You must take atleast 3 courses and atmost 5 courses." << endl;
            return;
        }
        else
        {
            cout << "Enter the total number of courses you took till last trimester: ";
            cin >> *totalCourses;

            if (*totalCourses <= 0 || *totalCourses > 50)
            {
                cout << endl
                     << "The number of courses entered is not valid!";
            }
            else
            {
                cout << "Enter your previous TGPA score: ";
                cin >> *previousTGPA;

                if (*previousTGPA < 0 || *previousTGPA > 10)
                {
                    cout << "Invalid input! Enter a valid TGPA score." << endl;
                    return;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // get all the registered courses
                for (int i = 0; i < *trimesterCourseCount; i++)
                {
                    string course;
                    cout << "Name of course " << (i + 1) << " taken in this trimester: ";
                    getline(cin, course);
                    courses.push_back(course);
                }

                getScores();
            }
        }
    }
}

void Result::getScores()
{
    float sum = 0;
    // convert percentage to cgpa
    for (int i = 1; i <= *trimesterCourseCount; i++)
    {
        float score = 0.0;
        cout << "Enter your score (in percentage) for course " << i << ": ";
        cin >> score;

        if (score < 0 || score > 100)
        {
            cout << "Invalid score entered for course " << i << ". Please enter a valid percentage." << endl;
            return;
        }
        else
        {
            sum = sum + score;
        }
    }

    *cgpaScore = sum / (10 * *trimesterCourseCount);

    *currentTGPA = ((*previousTGPA * *totalCourses * 10) + sum) / (10 * (*trimesterCourseCount + *totalCourses));
}

void Result::printDetails()
{
    // formatting the transcript outline
    cout << endl
         << "----------------------------------------------" << endl
         << endl
         << "SIAS - KREA UNIVERSITY"
         << endl
         << endl
         << endl
         << "STUDENT TRANSCRIPT"
         << endl
         << "----------------------------------------------"
         << endl
         << endl;
    cout << "Student name: " << *name << endl
         << endl
         << "Student ID: " << *studentId << endl;

    cout << endl
         << "Courses taken this trimester: " << endl;
    for (int i = 0; i < *trimesterCourseCount; i++)
    {
        cout << courses[i] << endl;
    }

    cout << endl
         << "Your CGPA score is: " << setprecision(2) << *cgpaScore << endl;
    cout << endl
         << "Your current TGPA score is: " << setprecision(2) << *currentTGPA << endl;
}