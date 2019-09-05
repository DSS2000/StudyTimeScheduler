## **Reading CSV File 4/16**

The CSV file is being read. The Boost library is used to tokanize the input where needed. The database CSV file can also be queried and the required average GPA is extracted.

https://www.youtube.com/watch?v=G3MbSpLWAbk

TODO - return some sort of error when course input is invalid.



## **Adding GUI 4/18**

Added the exisiting files to a new project created by Project Generator and including the ofxDatGui library. It was quite hard to include the ofxDatGui libraries after having already created a project, so I had to follow the steps on ofxDatGui's website to create a new project and shift my files.

The GUI has been created. A drop down is used to take the input of the number of hours of study. For the input of the 5 courses a simple text box is used. The GUI objects have been linked with the backend and the inputs can be stored.

TODO - Link drop down input to back end.


## **Converting GUI to Backend & Added Time Algorithm 4/19**

Linked up the drop down to back end. GUI complete. 

Algorithm added to figure out the time required for each course. The relative time calculated to divide the pie chart.


## **Working with Pie Chart 4/20**

Used existing code to create a basic pie chart. 
Bugs :-
[x] Gap in the chart
[.] Unable to divide according to time.


## **Pie Chart divided 4/22**
Pie divided according to time weightage. Cumulative division needed when calling the function.

Bugs - 
 Gap in Pie Chart. Need to modify part of the pie chart class.
 
 ## **Pie Chart Bug Fixed 4/26**
 Loop needs to move till 32 segments for full circle. Was earlier < instead of <=. GUI brushed up a bit and pie chart legend created.


 ## **Pie Chart Bug Fixed 4/28**
 Loop needs to move till 32 segments for full circle. Was earlier < instead of <=. GUI brushed up a bit and pie chart legend created.

## **Added Error Handling 4/29**
Added error handling features. Can now ignore invalid inputs instead of crashing the program. User can now also change the input and it will be registered in back end.

## **Added Final GUI 4/30**
The code was brushed up and GUI modified.

## **Pie bug Fixed 5/1**
The program can now accept less than 5 courses as well. If statement created to only add to GPA when the GPA function returns a valid value. When no input is there, the if block does not get executed.
