#include "ofApp.h"

void ofApp::setup(){
    video.load("source.mp4");
    video.play();
    shader.load("shader/chromaKey");
}

void ofApp::update(){
    video.update();
}

void ofApp::draw(){
    ofBackgroundGradient(ofColor(128), ofColor(31), OF_GRADIENT_LINEAR);
    float difference = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
    shader.begin();
    shader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 1.0, 0.0));
    shader.setUniform1f("difference", difference);
    video.draw(0, 0);
    shader.end();
}