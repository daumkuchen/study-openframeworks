#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber camera;
    ofxCv::FlowFarneback farneback;
    ofxCv::FlowPyrLK pyrLk;
    ofxCv::Flow* curFlow;
    
    ofxPanel gui;
    ofxFloatSlider pyrScale;
    ofxIntSlider levels;
    ofxIntSlider winsize;
    ofxIntSlider iterations;
    ofxIntSlider polyN;
    ofxFloatSlider polySigma;
    ofxIntSlider winSize;
    ofxIntSlider maxLevel;
    ofxFloatSlider maxFeatures;
    ofxFloatSlider quilityLevel;
    ofxFloatSlider minDistance;
    
    ofxToggle OPTFLOW_FARNEBACK_GAUSSIAN;
    ofxToggle userFarneback;
    
};
