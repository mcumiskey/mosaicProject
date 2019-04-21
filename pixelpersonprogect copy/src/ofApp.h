#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <vector>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        //int [] makeColorArray();
        void drawGrid(int gridSize);
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
    
    ofTrueTypeFont VT323; //i like this font
    ofVideoGrabber  capture; //grabber
    vector<vector<ofColor>> colors;
    int camWidth, camHeight;
    int gridSize;
};
