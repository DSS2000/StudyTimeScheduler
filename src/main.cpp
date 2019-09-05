#include "ofMain.h"
#include "ofApp.h"
#include "ofxDatGui.h"
#include <stdio.h>
#include "ProcessData.hpp"
#include "Caller.hpp"
const int kWINDOWSIZE = 500;
//========================================================================
int main( ){
    //Open up a window and run the program
	ofSetupOpenGL(kWINDOWSIZE,kWINDOWSIZE,OF_WINDOW);
	ofRunApp(new ofApp());
    cout << "We have now exited the app";
}
