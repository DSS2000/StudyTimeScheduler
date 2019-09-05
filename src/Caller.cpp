//
//  Caller.cpp
//  StudyTimeScheduler
//
//  Created by Dhruv Sirsikar on 4/19/19.
//

#include "Caller.hpp"
#include "ofApp.h"
#include "ProcessData.hpp"
#include "TimeCalculator.hpp"
std::vector<std::string> vec;
std::vector<double> vectorTime;
int choice;

//Creates the main vector used for keeping all the courses
void mainCaller(string s) {
    vec.push_back(s);
    cout << "Inside Main Caller " << s  << "\n";
}

//Keep the choice chosen in dropdown
void putDropChoice(int s) {
    choice = s + 1;
    cout << "In Put Drop Choice " << choice << "\n";
}

//Read CSV file and call apporpriate functions
void runApp() {
    CSVReader reader("/Users/dhruvsirsikar/Documents/of_v0.10.1_osx_release/apps/myApps/final-project-DSS2000/fa2018.csv");
    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = reader.getData();
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    int counter = 0;
    //Print out info about each course
    for (double d : DivideTime(choice, vec)) {
        cout << "GPA FOR " << vec[counter] << " IS " << GetAverageGPA(vec[counter++]) << " and time is " << d * choice << "\n";
        vectorTime.push_back(d*choice);
    }
}

//Helper to get choice in dropdown in other classes
int getChoice() {
    return choice;
}

//Helped to get list of courses chosen
vector<string> getCoursesList() {
    return vec;
}

//Helper to get vector of time as divided.
vector<double> getVectorTime() {
    return vectorTime;
}
