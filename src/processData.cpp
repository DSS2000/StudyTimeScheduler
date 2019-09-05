//
//  ProcessData.cpp
//  StudyTimeScheduler
//
//  Created by Dhruv Sirsikar on 4/19/19.
//

#include "ProcessData.hpp"
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <stdio.h>
const int kCourseRow = 1;
const int kNumberRow = 2;

//Convert to vector, when courses are entered as a Comma seperated list
std::vector<std::string> ConvertToVector(std::string input) {
    std::string internal;
    std::vector<std::string> vec;
    for (char a : input) {
        if (a == ' ') {
            vec.push_back(internal);
            internal = "";
        }
        internal += a;
    }
    return vec;
}

//Tokenize the string to get individual courses
std::vector<std::string> Tokenizer(std::string str, std::string del) {
    std::vector<std::string> vec;
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> sep{","};
    tokenizer tok{str, sep};
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it) {
        vec.push_back(*it);
    }
    return vec;
}

/*
 * Parses through csv file line by line and returns the data
 * in vector of vector of strings.
 */
std::vector<std::vector<std::string> > CSVReader::getData() {
    std::ifstream file(fileName);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    while (getline(file, line)){
        std::vector<std::string> vec;
        vec.push_back(line.substr(0, line.find(delimeter)));
        vec = Tokenizer(line, ",");
        dataList.push_back(vec);
    }
    file.close();
    return dataList;
}

//Get the average GPA from the CSV file for each.
std::string GetAverageGPA(std::string course) {
    CSVReader reader("/Users/dhruvsirsikar/Documents/of_v0.10.1_osx_release/apps/myApps/final-project-DSS2000/fa2018.csv");
    std::vector<std::vector<std::string> > dataList = reader.getData();
    for (std::vector<std::string> vec : dataList) {
        std::string line = vec[kCourseRow] + vec[kNumberRow];
        if (line == course) {
            return vec[vec.size() - 1];
        }
    }
    return "";
}

