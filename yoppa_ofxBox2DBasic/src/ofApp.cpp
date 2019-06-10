#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    //init box2d
    box2d.init();

    //setup box2d world
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    
    //setup box2d circle
    circle.setPhysics(3.0, 0.53, 0.1);
    circle.setup(box2d.getWorld(), ofGetWidth() / 2.0, 100, 40);
}

void ofApp::update(){
    //update box2d
    box2d.update();
}

void ofApp::draw(){
    //draw circle
    ofSetColor(0, 127, 255);
    circle.draw();
}
