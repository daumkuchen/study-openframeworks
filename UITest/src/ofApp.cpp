#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetWindowShape(WIDTH + padding, HEIGHT + padding);
    
    ofTrueTypeFont::setGlobalDpi(72);
    font.load("font/OpenSans-Bold.ttf", 12);
    font.setLineHeight(12);
    font.setLetterSpacing(1.0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawWireFrame();
    
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

void ofApp::drawRect(
                     string text,
                     float posx,
                     float posy,
                     float sizex,
                     float sizey,
                     ofColor color,
                     bool border){
    
    ofPushMatrix();
    ofSetColor(color);
    if(border) ofNoFill();
    ofDrawRectangle(posx + padding, posy + padding, sizex - padding, sizey - padding);
    ofSetColor(255);
    
    // fixed top
    // font.drawString(text, posx + padding * 2, posy + padding * 2 + 10);
    
    // fixed bottom
    font.drawString(text, posx + padding * 2, posy + sizey - padding);
    
    ofPopMatrix();
    
}

void ofApp::drawWireFrame(){
    
    drawRect(
             "Main View",
             0,
             0,
             WIDTH * one_third * 2,
             HEIGHT * one_third * 2,
             (25),
             false);
    
    drawRect(
             "Information & Effect",
             0,
             HEIGHT * one_third * 2,
             WIDTH * one_third,
             HEIGHT * one_third,
             (25),
             false);
    
    drawRect(
             "Beat Monitor",
             WIDTH * one_third,
             HEIGHT * one_third * 2,
             WIDTH * one_third * one_half,
             HEIGHT * one_third,
             (25),
             false);
    
    drawRect(
             "Audio In Monitor",
             WIDTH * one_third + WIDTH * one_third * one_half,
             HEIGHT * one_third * 2,
             WIDTH * one_third * one_half,
             HEIGHT * one_third,
             (25),
             false);
    
    for(int i = 0; i < num_clip; i++){
        
        bool even = i % 2 == 0;
        
        drawRect(
                 "Clip View: " + ofToString(i + 1),
                 even ? WIDTH * one_third * 2 : WIDTH * one_third * 2 + WIDTH * one_third * one_half,
                 round(ofMap(i, 0, num_clip - 1, 0, num_clip / 2 - 1)) * (HEIGHT * one_fourth),
                 WIDTH * one_third * one_half,
                 HEIGHT * one_fourth,
                 (25),
                 false);
        
    }
    
    //    for(int i = 0; i < num_clip; i++){
    //
    //        bool one_to_four = i < num_clip / 2;
    //
    //        drawRect(
    //                 "Clip View: " + ofToString(i + 1),
    //                 one_to_four ? WIDTH * one_third * 2 : WIDTH * one_third * 2 + WIDTH * one_third * one_half,
    //                 one_to_four ? i * (HEIGHT * one_fourth) : (i - num_clip / 2) * (HEIGHT * one_fourth),
    //                 WIDTH * one_third * one_half,
    //                 HEIGHT * one_fourth,
    //                 (25),
    //                 false);
    //
    //    }
    
}
