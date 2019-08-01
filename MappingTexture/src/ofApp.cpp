#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofLoadImage(image_texture, "images/mona_default.jpg");
	image_texture.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);

	points[0].x = init_x;
	points[0].y = init_x;
	points[1].x = init_y;
	points[1].y = init_x;
	points[2].x = init_y;
	points[2].y = init_y;
	points[3].x = init_x;
	points[3].y = init_y;

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(ofColor(255, 255, 255));

	image_texture.draw(points[0],
								  points[1],
								  points[2],
								  points[3]);

	ofSetColor(corner_index == 0 ? ofColor(255, 0, 0) : ofColor(255, 255, 255));
	ofEllipse(points[0].x, points[0].y, 10, 10);

	ofSetColor(corner_index == 1 ? ofColor(255, 0, 0) : ofColor(255, 255, 255));
	ofEllipse(points[1].x, points[1].y, 10, 10);

	ofSetColor(corner_index == 2 ? ofColor(255, 0, 0) : ofColor(255, 255, 255));
	ofEllipse(points[2].x, points[2].y, 10, 10);

	ofSetColor(corner_index == 3 ? ofColor(255, 0, 0) : ofColor(255, 255, 255));
	ofEllipse(points[3].x, points[3].y, 10, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	/*
	if (key == '1') {
		corner_index = 0;
	}

	if (key == '2') {
		corner_index = 1;
	}

	if (key == '3') {
		corner_index = 2;
	}

	if (key == '4') {
		corner_index = 3;
	}

	if (key == OF_KEY_LEFT) {
		points[corner_index].x -= 30;
	}

	if (key == OF_KEY_RIGHT) {
		points[corner_index].x += 30;
	}

	if (key == OF_KEY_UP) {
		points[corner_index].y -= 30;
	}

	if (key == OF_KEY_DOWN) {
		points[corner_index].y += 30;
	}
	*/

	if (key == 'r') {
		points[0].x = init_x;
		points[0].y = init_x;
		points[1].x = init_y;
		points[1].y = init_x;
		points[2].x = init_y;
		points[2].y = init_y;
		points[3].x = init_x;
		points[3].y = init_y;
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

	points[corner_index].x = x;
	points[corner_index].y = y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	for (int i = 0; i < 4; i++) {
		if (points[i].x + nb / 2 > x && points[i].x - nb / 2 < x) {
			if (points[i].y + nb / 2 > y && points[i].y - nb / 2 < y) {
				corner_index = i;
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

	corner_index = 9999;

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
