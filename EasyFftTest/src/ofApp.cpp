#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	fft.setup(sampleNum);

}

//--------------------------------------------------------------
void ofApp::update(){

	fft.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofLog() << fft.getBins().size() << endl;
	ofBackground(0);
	for (int i = 0; i < fft.getBins().size(); i++) {
		ofDrawCircle(ofGetWidth() * 2 * float(i) / sampleNum, ofGetHeight() * (1 - fft.getBins()[i]), 2);
	}

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
