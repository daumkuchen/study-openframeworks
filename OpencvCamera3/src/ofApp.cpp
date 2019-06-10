#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    // camera
    camera.initGrabber(320, 240);
    
    // gui
    gui.setup();
    gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
    gui.add(levels.setup("levels", 4, 1, 8));
    gui.add(winsize.setup("levels", 8, 4, 64));
    gui.add(iterations.setup("iterations", 2, 1, 8));
    gui.add(polyN.setup("polyN", 7, 5, 10));
    gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
    gui.add(OPTFLOW_FARNEBACK_GAUSSIAN.setup("OPTFLOW_FARNEBACK_GAUSSIAN", false));
    gui.add(userFarneback.setup("userFarneback", true));
    gui.add(winSize.setup("winSize", 32, 4, 64));
    gui.add(maxLevel.setup("maxLevel", 3, 0, 8));
    gui.add(quilityLevel.setup("levels", 0.01, 0.001, 0.02));
    gui.add(minDistance.setup("minDistance", 4, 1, 16));
    
    curFlow = &farneback;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();
    
    if(camera.isFrameNew()) {
        
        if(userFarneback) {
            
            // Farnbackの密なオプティカルフロー
            curFlow = &farneback;
            farneback.setPyramidScale(pyrScale);
            farneback.setNumLevels(levels);
            farneback.setWindowSize(winsize);
            farneback.setNumIterations(iterations);
            farneback.setPolyN(polyN);
            farneback.setPolySigma(polySigma);
            farneback.setUseGaussian(OPTFLOW_FARNEBACK_GAUSSIAN);
            
        } else {
            
            // 画像ピラミッドを利用した、密なオプティカルフロー
            curFlow = &pyrLk;
            pyrLk.setMaxFeatures(maxFeatures);
            pyrLk.setQualityLevel(quilityLevel);
            pyrLk.setMinDistance(minDistance);
            pyrLk.setWindowSize(winSize);
            pyrLk.setMaxLevel(maxLevel);
            
        }
        
        // オプティカルフローを計算
        curFlow->calcOpticalFlow(camera);
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    ofSetColor(255);
    camera.draw(0, 0, ofGetWidth(), ofGetHeight());
    curFlow->draw(0, 0, ofGetWidth(), ofGetHeight());
    
    gui.draw();

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
