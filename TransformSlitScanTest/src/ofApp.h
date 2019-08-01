#pragma once

#include "ofMain.h"

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

	void setPixel(int horizontal, int vertical, unsigned char R,
		unsigned char G, unsigned char B, int w, unsigned char pixels[]);
	void getPixel(int horizontal, int vertical, unsigned char* R,
		unsigned char* G, unsigned char* B, int w, unsigned char pixels[]);

	ofVideoPlayer player;
	ofVideoGrabber grabber;

	ofTexture texture;
	unsigned char *texpixels, *vidpixels;

	int video_width = 160;
	int video_height = 120;
	int video_slice_x = video_width / 2;
	int window_width = 1000;
	int window_height = video_height;
	int draw_position_x = 0;
	bool new_frame = false;

};
