#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);

	soundStream.printDeviceList();

	int bufferSize = 256;

	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);

	bufferCounter = 0;
	drawCounter = 0;
	smoothedVol = 0.0;
	scaledVol = 0.0;

	ofSoundStreamSettings settings;

	auto devices = soundStream.getMatchingDevices("default");
	if (!devices.empty()) {
		settings.setInDevice(devices[0]);
	}

	settings.setInListener(this);
	settings.sampleRate = 44100;
	settings.numOutputChannels = 0;
	settings.numInputChannels = 1;
	settings.bufferSize = bufferSize;
	soundStream.setup(settings);

}

//--------------------------------------------------------------
void ofApp::update() {

	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	volHistory.push_back(scaledVol);

	if (volHistory.size() >= 400) {
		volHistory.erase(volHistory.begin(), volHistory.begin() + 1);
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(225);
	ofDrawBitmapString("AUDIO INPUT EXAMPLE", 32, 32);
	ofDrawBitmapString("press 's' to unpause the audio\n'e' to pause the audio", 31, 92);

	ofNoFill();

	// draw the left channel:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(32, 170, 0);

	ofSetColor(225);
	ofDrawBitmapString("Left Channel", 4, 18);

	ofSetLineWidth(1);
	ofDrawRectangle(0, 0, 512, 200);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	for (unsigned int i = 0; i < left.size(); i++) {
		ofVertex(i * 2, 100 - left[i] * 180.0f);
	}
	ofEndShape(false);

	ofPopMatrix();
	ofPopStyle();


	// draw the right channel:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(32, 370, 0);

	ofSetColor(225);
	ofDrawBitmapString("Right Channel", 4, 18);

	ofSetLineWidth(1);
	ofDrawRectangle(0, 0, 512, 200);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	//for (unsigned int i = 0; i < right.size(); i++) {
	//	ofVertex(i * 2, 100 - right[i] * 180.0f);
	//}
	ofVertex(2, 100 - scaledVol);
	ofEndShape(false);

	ofPopMatrix();
	ofPopStyle();


	// draw the average volume:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(565, 170, 0);

	ofSetColor(225);
	ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0), 4, 18);
	ofDrawRectangle(0, 0, 400, 400);

	ofSetColor(245, 58, 135);
	ofFill();
	ofDrawCircle(200, 200, scaledVol * 190.0f);


	// lets draw the volume history as a graph
	ofBeginShape();
	for (unsigned int i = 0; i < volHistory.size(); i++) {
		if (i == 0) ofVertex(i, 400);

		ofVertex(i, 400 - volHistory[i] * 70);

		if (i == volHistory.size() - 1) ofVertex(i, 400);
	}
	ofEndShape(false);

	ofPopMatrix();
	ofPopStyle();

	drawCounter++;

	ofSetColor(225);
	string reportString = "buffers received: " + ofToString(bufferCounter) + "\ndraw routines called: " + ofToString(drawCounter) + "\nticks: " + ofToString(soundStream.getTickCount());
	ofDrawBitmapString(reportString, 32, 589);

}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & input) {

	float curVol = 0.0;

	int numCounted = 0;

	for (size_t i = 0; i < input.getNumFrames(); i++) {

		//left[i] = input[i * 2] * 0.5;
		//right[i] = input[i * 2 + 1] * 0.5;

		//curVol += left[i] * left[i];
		//curVol += right[i] * right[i];
		//numCounted += 2;

		left[i] = input[i] * 0.5;
		curVol += left[i] * left[i];
		numCounted++;

	}

	curVol /= (float)numCounted;

	curVol = sqrt(curVol);

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;

	bufferCounter++;

	std::cout << ofToString(smoothedVol) << std::endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == 's') {
		soundStream.start();
	}

	if (key == 'e') {
		soundStream.stop();
	}

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