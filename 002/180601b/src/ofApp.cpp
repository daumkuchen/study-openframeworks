#include "ofApp.h"

void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetWindowTitle("Chroma Key Test.");
    
    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    grabber.setDeviceID(1);
    
}

void ofApp::update(){
    
    grabber.update();
    
}

void ofApp::draw(){
    
    // ofBackgroundGradient(ofColor(128), ofColor(31), OF_GRADIENT_LINEAR);
    // ofBackground(255, 0, 127);
    // ofBackground(0, 0, 0);
    
    // 閾値を指定
    float difference = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
 
    // shader
    shader.load("shader/chromaKey");
    shader.begin();
    shader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 0.0, 0.0));
    shader.setUniform1f("difference", difference);
    grabber.draw(0, 0);
    shader.end();
    
}
