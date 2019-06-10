#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetWindowTitle("openframeworks");
    
    ofSetColor(0);
    ofSetColor(255);
    
    this->image.load("images/image.jpg");
    
    this->screen_width = ofGetScreenWidth();
    this->screen_height = ofGetScreenHeight();
    this->window_width = ofGetWindowWidth();
    this->window_height = ofGetWindowHeight();
    this->noise_seed_x = ofRandom(100);
    this->noise_seed_y = ofRandom(100);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int x = ofMap(ofNoise(this->noise_seed_x + ofGetFrameNum() * 0.03), 0, 1, this->screen_width * -0.2, this->screen_width * 1.2) - this->window_width * 0.5;
    int y = ofMap(ofNoise(this->noise_seed_y + ofGetFrameNum() * 0.03), 0, 1, this->screen_height * -0.2, this->screen_height * 1.2) - this->window_height * 0.5;
    this->window_position = ofPoint(x, y);
    ofSetWindowPosition(this->window_position.x, this->window_position.y);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(this->window_position * -1);
    this->image.draw(0, 0);
    
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
