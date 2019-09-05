# ** Time Management Graphic Tool **

## **Idea**
This project is intended to be used as a time management tool by students at UIUC to divide their hours studying efficiently between various classes. While come classes are relatively easy and require less time, others can be challenging requiring hours of work. Given that all classes are not the same in difficulty, this project takes into account their difficulty (which is assumed to be directly corelated with their average GPAs) and divides study time accordingly.

The project takes an input of the number of hours the user would like to spend studying. It then asks for upto 5 classes which the user is taking for which the time can be divided. Through an existing databse, the inputted course will be found and the average GPA for the same will be extracted. Through an algorithm to weigh the time needed on a course with respect to it's average GPA, the time will then be divided.

The next part would be showing this divided study time in the form of a pie chart. 

## **Technicalities**

The data set for the List of all GPAs at UIUC will be sourced from 

https://github.com/wadefagen/datasets/blob/master/gpa/raw/fa2018.csv

This CSV file contains a list of all courses and their average GPAs. A user can put in a course in the format specified (eg: - CS 126) and the program will query it into this data base to match it to the average GPA. It will then rank them in order of difficulty and weigh the time needed accordingly. 


## **List of Libraries**

1. For input the ofxDatGui library will be used. It will also be used to make a pie chart.
2. For string manipulation, Boost library will be used.






