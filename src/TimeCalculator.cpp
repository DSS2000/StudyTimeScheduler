//
//  TimeCalculator.cpp
//  StudyTimeScheduler
//
//  Created by Dhruv Sirsikar on 4/21/19.
//

#include "TimeCalculator.hpp"
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "ProcessData.hpp"
const double FULL_GPA = 4.0;
std::vector<double> hours;

//Divide time in order of difficulty
std::vector<double> DivideTime(int totalHours, std::vector<std::string> courses) {
    std::vector<double> gpa;
    double sum = 0;
    for (std::string s: courses) {
        std::string word = GetAverageGPA(s);
        if (word != "") {
            double avGPA = FULL_GPA - stod(word);
            gpa.push_back(avGPA);
            sum += avGPA;
        }
    }
    for (double d : gpa) {
        hours.push_back(d/sum);
    }
    return hours;
}

//Return number of hours to study for each course
std::vector<double> getVector() {
    return hours;
}
