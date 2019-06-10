#include "ofApp.h"

using namespace ofxCv;

// --------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    cam.setup(640, 480);
    tracker.setup();
    
}

// --------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }
    
}

// --------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    cam.draw(0, 0);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    if(tracker.getFound()) {
        tracker.draw();
        ofMesh objectMesh = tracker.getObjectMesh();
        ofMesh meanMesh = tracker.getMeanObjectMesh();
        
        ofSetupScreenOrtho(640, 480, -1000, 1000);
        ofTranslate(100, 100);
        ofScale(5,5,5);
        cam.getTexture().bind();
        meanMesh.draw();
        cam.getTexture().unbind();
    }
    
}

// --------------------------------------------------------------
void ofApp::exit(){
    
//    tracker.stopThread();
//    tracker.waitForThread();
    
}

// --------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'r') {
        tracker.reset();
    }
    
}

// --------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

// --------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

// --------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

// --------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

// --------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

// --------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

// --------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

// --------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

// --------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

// --------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
