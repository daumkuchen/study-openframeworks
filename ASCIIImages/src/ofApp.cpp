#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofBackground(0);

	font.load("OpenSans-Bold.ttf", 12);
	image.load("apple.png");

	pix = image.getPixelsRef();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	// image.draw(0, 0);

	ofColor word_color;
	vector<string> word = { "A", "P", "L", "E" };

	ofTranslate((ofGetWidth() - image.getWidth()) * 0.5, (ofGetHeight() - image.getHeight()) * 0.5);

	for (int x = 0; x < image.getWidth(); x += font.getSize()) {

		for (int y = 0; y < image.getHeight(); y += font.getSize()) {

			ofColor pix_color = pix.getColor(x, y);
			if (pix_color == ofColor(0)) {
				continue;
			}

			// int word_index = ofMap(ofNoise(x * 0.015, y * 0.015 + ofGetFrameNum() * 0.2), 0, 1, 0, word.size());
			int word_index = ofMap(ofNoise(x * 0.015, y * 0.015), 0, 1, 0, word.size());

			// word_color.setHsb(ofMap(word_index, 0, word.size(), 0, 239), 200, 255);
			word_color.setBrightness(ofMap(word_index, 0, word.size(), 155, 255));

			ofSetColor(word_color);

			font.drawString(word[word_index], x, y);

		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 's') {
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.save("screenshot.jpg");

	}

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
