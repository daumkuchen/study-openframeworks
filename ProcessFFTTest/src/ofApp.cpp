#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofBackground(0);
	fft.setup();
	fft.setNumFFTBins(16);
	fft.setNormalize(true);

}

//--------------------------------------------------------------
void ofApp::update() {

	fft.update();

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(255);
	ofDrawRectangle(0, ofGetHeight(), ofGetWidth() / 3, -ofGetHeight() * fft.getLowVal());
	ofDrawRectangle(ofGetWidth() / 3, ofGetHeight(), ofGetWidth() / 3, -ofGetHeight() * fft.getMidVal());
	ofDrawRectangle(ofGetWidth() * 2 / 3, ofGetHeight(), ofGetWidth() / 3, -ofGetHeight() * fft.getHighVal());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}