#include "ofApp.h"

void ofApp::setup(){
    
	ofSetFrameRate(60);

	video.initGrabber(ofGetWidth(), ofGetHeight());
	video.setDeviceID(1);
    
}

void ofApp::update(){
    
	video.update();
    
}

void ofApp::draw(){

	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	// video.draw(0, 0);

     ofBackgroundGradient(ofColor(128), ofColor(31), OF_GRADIENT_LINEAR);
     ofBackground(255, 0, 127);
     ofBackground(0, 0, 0);
    
    // 閾値を指定
    float difference = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
    
    backgroundShader.load("", "shader/background.frag");
    backgroundShader.begin();
    backgroundShader.setUniform1f("time", ofGetElapsedTimef());
    backgroundShader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    backgroundShader.end();
    
    // chromakeyShader
    chromakeyShader.load("shader/chromaKey");
    chromakeyShader.begin();
    chromakeyShader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 0.0, 0.0));
    chromakeyShader.setUniform1f("difference", difference);
    video.draw(0, 0);
    chromakeyShader.end();

}
