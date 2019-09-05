#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include <vector>
#include <string>
#include "Caller.hpp"


//vector<string> vec;
class ofApp : public ofBaseApp{

	public:
    int c = 0;
    ofMesh pie;
    ofxDatGuiTextInput* hourInput;
    ofxDatGuiTextInput* myInput;
    ofxDatGuiTextInput* myInput2;
    ofxDatGuiTextInput* myInput3;
    ofxDatGuiTextInput* myInput4;
    ofxDatGuiTextInput* myInput5;
    ofxDatGuiButton* myButton;
    ofxDatGuiDropdown* myDrop;
    ofxDatGuiMatrix* myPad;
    ofxDatGuiScrollView* view;
    ofxDatGuiLabel* courseOne;
    ofxDatGuiLabel* courseTwo;

    void onTextInputEvent(ofxDatGuiTextInputEvent e){
        mainCaller(e.text);
    }
    void onButtonEvent(ofxDatGuiButtonEvent e){
        runApp();
        draw();
    }
    void onDropdownEvent(ofxDatGuiDropdownEvent e){
        putDropChoice(e.child);
    }
    void changCo(int c);
    ofxDatGui* gui;
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
