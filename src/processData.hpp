//
//  ProcessData.hpp
//  StudyTimeScheduler
//
//  Created by Dhruv Sirsikar on 4/19/19.
//

#ifndef ProcessData_hpp
#define ProcessData_hpp
#include <stdio.h>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>

std::vector<std::string> ConvertToVector(std::string input);
class CSVReader {
    std::string fileName;
    std::string delimeter;
public:
    CSVReader(std::string filename, std::string delm = ",") :
    fileName(filename), delimeter(delm){ }
    
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > getData();
};

std::vector<std::string> Tokenizer(std::string str, std::string del);
std::string GetAverageGPA(std::string course);

#endif /* ProcessData_hpp */
