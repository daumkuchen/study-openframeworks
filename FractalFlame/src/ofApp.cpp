#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // ofBackground(0, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.load("shader.vs", "shader.fs");
    
    shader.begin();
    
    shader.setUniform1fv("uWeight", uWeight, 2);
    shader.setUniform1fv("uAffineParams", uAffineParams, 18);
    shader.setUniform1fv("uVariationParams", uVariationParams, 15);
    shader.setUniform1fv("uColorParams", uColorParams, 9);
    shader.setUniform2f("uScale", uScale.x, uScale.y);
    shader.setUniform2f("uShift", uShift.x, uShift.y);
    shader.setUniform1i("uNumColor", 3);
    shader.setUniform1f("uSeed", ofGetElapsedTimef());
    
    mesh.draw();
    shader.end();
    
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
