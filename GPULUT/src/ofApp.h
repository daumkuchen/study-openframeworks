#pragma once

#include "ofMain.h"
#include "ofGpuLut.h"
#include "ofxDirectShowPlayer.h"

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

	ofGpuLut luts[9];
	ofImage lutImg;

	ofVideoGrabber video;
	ofxDirectShowPlayer videop;
	ofTexture videot;

	bool isThumbnailView;

	int lutIndex;
	string lutNames[9];
	string description;
	float thumbnailWidth, thumbnailHeight;

};
