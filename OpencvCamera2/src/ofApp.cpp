#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    camera.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
    background.setThresholdValue(20);
    
    resetBackgroundButton.addListener(this, &ofApp::resetBackgroundPressed);
    
    gui.setup();
    gui.add(bgThresh.setup("background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset background"));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();
    
    if(camera.isFrameNew()) {
        
        // 背景差分画像を生成
        background.setThresholdValue(bgThresh);
        background.update(camera, thresholded);
        thresholded.update();
        
        // 背景差分画像の輪郭抽出
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // 差分画像を描画
    ofSetColor(255);
    thresholded.draw(0, 0);
    
    // 輪郭抽出結果を描画
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    
    // gui
    gui.draw();

}

void ofApp::resetBackgroundPressed(){
    background.reset();
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
