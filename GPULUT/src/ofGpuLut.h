#pragma once

#include "ofMain.h"

#define STRINGIFY(e) #e

class ofGpuLut {

private:
	ofShader lutShader;
	ofTexture lut;
	string vertexShader;
	string fragmentShader;
	ofImage lutImage;

public:
	ofGpuLut();
	~ofGpuLut();

	void load(ofTexture lutTexture);
	void load(ofImage lutImage);
	void load(string path);
	void begin();
	void end();

};