#pragma once

#include "ofMain.h"
#include "PingPongBuffer.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	int w, h;
	ofShader simulateShader, renderShader;

	PingPongBuffer pingPong;

	ofxPanel gui;
	ofParameter<float> feed;
	ofParameter<float> kill;
	ofParameter<float> dA;
	ofParameter<float> dB;
	ofParameter<float> dt;
	ofParameter<ofFloatColor> color1;
	ofParameter<ofFloatColor> color2;
	ofParameter<ofFloatColor> color3;
	ofParameter<ofFloatColor> color4;
	ofParameter<ofFloatColor> color5;

};
