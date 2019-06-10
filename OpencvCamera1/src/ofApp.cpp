#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    if(cam.isFrameNew()) {
        contourFinder.setThreshold(ofMap(mouseX, 0, ofGetWidth(), 0, 255));
        contourFinder.findContours(cam);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    cam.draw(0, 0);
    contourFinder.draw();
    
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
