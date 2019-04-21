#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 1024;
    camHeight = 768;
    capture.initGrabber(camWidth, camHeight); //initialize the videograbber
    
    //load font
    VT323.load("/Users/miles/Library/Fonts/VT323-Regular.ttf", 32);

    gridSize = 20;
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    capture.update(); // update with new frame
    
    //get the data from
    ofPixels pixel = capture.getPixels();
    
    colors.resize(pixel.getWidth(), vector<ofColor>(pixel.getHeight(), ofColor(255, 255, 255, 0)));
    
    if (capture.isFrameNew()) {
        
        //in a 2D way, get a color in each gridsized pixel
        for (int x = 0; x < pixel.getWidth(); x += gridSize) {
            for (int y = 0; y < pixel.getHeight(); y += gridSize) {
                //assign color
                ofColor color = pixel.getColor(x, y);
                //save the color in the 2D array []
                colors[x][y] = color;
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    //capture.draw(0, 0, camWidth, camHeight);
    if((gridSize <= 4) || (gridSize >= 222)){
        gridSize = 30;
    }

    drawGrid(gridSize);
    ofSetColor(255);
    VT323.drawString("Use the left and right arrows to adjust grid size", 20, 40);
    VT323.drawString("Grid Size: " +ofToString(gridSize), 20, 80);

}

void ofApp::drawGrid(int gridSize){
    
    for (int x = 0; x < capture.getWidth(); x += gridSize) {
        for (int y = 0; y < capture.getHeight(); y += gridSize) {
            //can't set them at x, x is only the width and this is 2D
            ofSetColor(colors[x][y]);
            ofDrawRectangle(x, y, gridSize, gridSize);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_RIGHT){
        gridSize++;
    }
    if (key == OF_KEY_LEFT){
        gridSize--;
    }
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
