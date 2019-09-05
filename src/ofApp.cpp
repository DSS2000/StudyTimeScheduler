#include "ofApp.h"
#include <stdio.h>
#include <string>
#include "Caller.hpp"
#include "generatePieMesh.h"
#include "TimeCalculator.hpp"

string s;
int co = 0;
bool flag = true;
const int kCorrectionFactor = 2;
const int kSegements = 32;
const int kRadius = 100;
const int kMesh = 0.5;
const int kFirstSegment = 1;
const int kSecondSegment = 2;
const int kThirdSegment = 3;
const int kFourhtSegment = 4;

//--------------------------------------------------------------



void ofApp::setup(){
    gui = new ofxDatGui(0,0);
    vector<string> vect = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"
    };
    
    myDrop = gui->addDropdown("Number of Hours", vect);
    myDrop->onDropdownEvent(this, &ofApp::onDropdownEvent);
    myDrop->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    myDrop->setWidth(500);
    
    myInput = gui->addTextInput("Course 1");
    myInput->ofxDatGuiComponent::setPosition(500, 600);
    myInput->onTextInputEvent(this, &ofApp::onTextInputEvent);
    myInput->setWidth(800, 0.2);
    myInput->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    myInput2 = gui->addTextInput("Course 2", "");
    myInput2->onTextInputEvent(this, &ofApp::onTextInputEvent);
    myInput2->setWidth(800, 0.2);
    myInput2->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    myInput3 = gui->addTextInput("Course 3", "");
    myInput3->onTextInputEvent(this, &ofApp::onTextInputEvent);
    myInput3->setWidth(800, 0.2);
    myInput3->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    myInput4 = gui->addTextInput("Course 4", "");
    myInput4->onTextInputEvent(this, &ofApp::onTextInputEvent);
    myInput4->setWidth(800, 0.2);
    myInput4->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    myInput5 = gui->addTextInput("Course 5", "");
    myInput5->onTextInputEvent(this, &ofApp::onTextInputEvent);
    myInput5->setWidth(800, 0.2);
    myInput5->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    myButton = gui->addButton("Calculate");
    myButton->setWidth(500);
    myButton->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    myButton->setBackgroundColor(ofColor::skyBlue);
    myButton->setStripeColor(ofColor::whiteSmoke);
    myButton->setLabelColor(ofColor::black);
    gui->onButtonEvent(this, &ofApp::onButtonEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    //view->update();
    draw();
}

//--------------------------------------------------------------
void ofApp::draw(){
    std::vector<double> hours = getVector();
    std::vector<double> fractions;
    double sum = 0;
    for (double d : hours) {
        sum += d;
    }
    double fracts[5] = {0,0,0,0,0};
    for (int i = 0; i < hours.size(); i++) {
        fracts[i] = (hours[i]/sum) * kSegements;
    }
    double total = 0;
    ofMesh mesh;
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(375, 320.0f );
    ofSetColor(ofColor::black);
    generatePieMesh(kMesh,0, fracts[0],kRadius,kSegements).draw();
    total += fracts[0];
    ofSetColor(ofColor::red);
    generatePieMesh(kMesh, total - kCorrectionFactor, total + fracts[1], kRadius, kSegements).draw();
    total += fracts[1];
    ofSetColor(ofColor::skyBlue);
    generatePieMesh(kMesh, total - kCorrectionFactor, total + fracts[2], kRadius, kSegements).draw();
    total += fracts[2];
    ofSetColor(ofColor::yellowGreen);
    generatePieMesh(kMesh, total - kCorrectionFactor, total + fracts[3], kRadius, kSegements).draw();
    total += fracts[3];
    ofSetColor(ofColor::lightCoral);
    generatePieMesh(kMesh, total - kCorrectionFactor, total + fracts[4], kRadius, kSegements).draw();
    total += fracts[4];
    ofPopStyle();
    ofPopMatrix();
    
    vector<double> vectorialTimes = getVectorTime();
    if (hours.size() != 0 && flag) {
        courseOne = gui->addLabel("For " + getCoursesList()[0] + " study for " + std::to_string((int)round(vectorialTimes[0])));
        courseOne->setPosition(0, 400);
        courseOne->setBackgroundColor(ofColor::black);
        if (vectorialTimes.size() > kFirstSegment) {
            courseTwo = gui->addLabel("For " + getCoursesList()[kFirstSegment] + " study for " + std::to_string((int)round(vectorialTimes[kFirstSegment])));
            courseTwo->setBackgroundColor(ofColor::red);
            courseTwo->setPosition(0, 420);
        }
        if (vectorialTimes.size() > kSecondSegment) {
            courseOne = gui->addLabel("For " + getCoursesList()[kSecondSegment] + " study for " + std::to_string((int)round(vectorialTimes[kSecondSegment])));
            courseOne->setBackgroundColor(ofColor::skyBlue);
        }
        if (vectorialTimes.size() > kThirdSegment) {
            courseOne = gui->addLabel("For " + getCoursesList()[kThirdSegment] + " study for " + std::to_string((int)round(vectorialTimes[kThirdSegment])));
            courseOne->setBackgroundColor(ofColor::yellowGreen);
        }
        if (vectorialTimes.size() > kFourhtSegment) {
            courseOne = gui->addLabel("For " + getCoursesList()[kFourhtSegment] + " study for " + std::to_string((int)round(vectorialTimes[kFourhtSegment])));
            courseOne->setBackgroundColor(ofColor::lightCoral);
        }
        flag = false;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
