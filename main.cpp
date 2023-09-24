#include "gradeReportSystem.h"

#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>

int main()
{

    // create a report using result class
    Result* report = new Result;

    // get student details
    report->getInfo();

    report->printDetails();

    delete report;

    return 0;
}


