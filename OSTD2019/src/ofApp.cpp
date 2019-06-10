#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofBackground(0);

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	// Fonts
	ofTrueTypeFont::setGlobalDpi(30);

	font.load("OpenSans-SemiBold.ttf", 250);

	this->fbo.allocate(ofGetWidth(), ofGetHeight());
	this->fbo.begin();
	ofClear(0);

	ofSetColor(0);
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	string word_1 = "ON-SCREEN";
	string word_2 = "TYPOGRAPHY DAY";
	this->font.drawString(word_1, this->font.stringWidth(word_1) * -0.5, this->font.stringHeight(word_1) * -0.1);
	this->font.drawString(word_2, this->font.stringWidth(word_2) * -0.5, this->font.stringHeight(word_2) * 1.1);

	this->fbo.end();
	this->fbo.readToPixels(this->pix);

}

//--------------------------------------------------------------
void ofApp::update(){

	ofSeedRandom(50);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofPushMatrix();
	font.load("OpenSans-SemiBold.ttf", 250);
	ofSetColor(55, 55, 55);
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	string word_1 = "ON-SCREEN";
	string word_2 = "TYPOGRAPHY DAY";
	this->font.drawString(word_1, this->font.stringWidth(word_1) * -0.5, this->font.stringHeight(word_1) * -0.1);
	this->font.drawString(word_2, this->font.stringWidth(word_2) * -0.5, this->font.stringHeight(word_2) * 1.1);
	ofPopMatrix();

	int number_of_circle = 200;

	vector<ofPoint> points;
	while (points.size() < number_of_circle) {

		int x = ofRandom(ofGetWidth());
		int y = ofRandom(ofGetHeight());

		ofColor pix_color = this->pix.getColor(x, y);
		if (pix_color != ofColor(0)) {
			continue;
		}

		float x_increase = ofMap(ofNoise(ofRandom(number_of_circle), ofGetFrameNum() * 0.005), 0, 1, -20, 20);
		float y_increase = ofMap(ofNoise(ofRandom(number_of_circle), ofGetFrameNum() * 0.005), 0, 1, -20, 20);
		x += x_increase;
		y += y_increase;

		points.push_back(ofPoint(x, y));
	}

	for (int i = 0; i < points.size(); i++) {

		ofColor color;
		// color.setHsb(ofRandom(255), 255, 255);

		ofSetColor(color);
		ofDrawCircle(points[i], 3);

		for (int j = 0; j < points.size(); j++) {

			float distance = points[i].distance(points[j]);
			if (distance < 50) {

				ofSetColor(color, ofMap(distance, 0, 50, 255, 0));
				ofDrawLine(points[i], points[j]);

			}
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(key == 's'){
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
