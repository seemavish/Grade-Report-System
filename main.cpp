#include "gradeReportSystem.h"
#include "gradeReportSystem.cpp"

#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>

int main()
{

    // create a report using result class
    Result report;

    // get student details
    report.getInfo();

    report.printDetails();
    return 0;
}


