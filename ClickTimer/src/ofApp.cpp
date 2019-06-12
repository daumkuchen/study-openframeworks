#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if(frame_count < max_count){
        frame_count++;
    } else {
        frame_count = 0;
    }
    
    loop_count = fmod(frame_count, bpm);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float size = loop_count / bpm * 100;
    ofSetColor(255, 0, 255);
    ofDrawEllipse(250, 250, size, size);
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    ofSetColor(0);
    ofDrawBitmapString("COUNT: " + ofToString(frame_count), 10, 20);
    
    ofSetColor(255, 0, 255);
    ofDrawBitmapString("BPM:  " + ofToString(bpm), 10, 40);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        
        bpm = frame_count;
        frame_count = 0;
        
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
