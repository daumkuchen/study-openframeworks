#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);

	simulateShader.load("shader/pass.vert", "shader/simulate.frag");
	renderShader.load("shader/pass.vert", "shader/render.frag");

	w = ofGetWidth();
	h = ofGetHeight();
	auto color = make_unique<float[]>(w * h * 3);
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			int i = y * w + x;
			color[i * 3 + 0] = 0.0;
			color[i * 3 + 1] = 0.0;
			color[i * 3 + 2] = 0.0;
		}
	}

	pingPong.allocate(w, h, GL_RGB32F);
	pingPong.src->getTexture().loadData(color.get(), w, h, GL_RGB32F);
	pingPong.dst->getTexture().loadData(color.get(), w, h, GL_RGB32F);

	gui.setup();

	//gui.add(feed.set("feed", 0.022, 0.0, 0.1));
	//gui.add(kill.set("kill", 0.051, 0.0, 0.1));
	//gui.add(dA.set("dA", 0.45, 0.0, 1.0));
	//gui.add(dB.set("dB", 0.22, 0.0, 1.0));
	//gui.add(dt.set("dt", 2.1, 1.0, 5.0));

	gui.add(feed.set("feed", 0.022, 0.0, 0.1));
	gui.add(kill.set("kill", 0.051, 0.0, 0.1));
	gui.add(dA.set("dA", 0.515, 0.0, 1.0));
	gui.add(dB.set("dB", 0.412, 0.0, 1.0));
	gui.add(dt.set("dt", 2.1, 1.0, 5.0));

	gui.add(color1.set("color1", ofFloatColor(0.0, 0.0, 0.0, 0.20), ofFloatColor(0.0, 0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0, 1.0)));    
	gui.add(color2.set("color2", ofFloatColor(0.8, 0.0, 0.0, 0.22), ofFloatColor(0.0, 0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0, 1.0)));    
	gui.add(color3.set("color3", ofFloatColor(0.0, 0.8, 0.0, 0.24), ofFloatColor(0.0, 0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0, 1.0)));
	gui.add(color4.set("color4", ofFloatColor(0.0, 0.0, 0.8, 0.26), ofFloatColor(0.0, 0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0, 1.0)));
	gui.add(color5.set("color5", ofFloatColor(1.0, 1.0, 1.0, 0.28), ofFloatColor(0.0, 0.0, 0.0, 0.0), ofFloatColor(1.0, 1.0, 1.0, 1.0)));    
	 
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	pingPong.dst->begin();
	ofClear(0);
	simulateShader.begin();
	simulateShader.setUniformTexture("u_prevBuffer", pingPong.src->getTexture(), 0);
	simulateShader.setUniform1f("u_feed", feed);
	simulateShader.setUniform1f("u_kill", kill);
	simulateShader.setUniform1f("u_dA", dA);
	simulateShader.setUniform1f("u_dB", dB);
	simulateShader.setUniform1f("u_dt", dt);
	pingPong.src->draw(0, 0, w, h);
	simulateShader.end();
	pingPong.dst->end();

	pingPong.swap();

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(0);

	renderShader.begin();
	renderShader.setUniformTexture("u_tex", pingPong.dst->getTexture(), 0);
	renderShader.setUniform4f("color1", color1);
	renderShader.setUniform4f("color2", color2);
	renderShader.setUniform4f("color3", color3);
	renderShader.setUniform4f("color4", color4);
	renderShader.setUniform4f("color5", color5);
	ofDrawRectangle(0, 0, w, h);
	renderShader.end();

	ofDisableDepthTest();

	gui.draw();
	ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	// ------------------------------------------------------------------
	// reference: http://mrob.com/pub/comp/xmorphia/pearson-classes.html
	// ------------------------------------------------------------------

	if (key == '1') {
		feed = 0.022;
		kill = 0.051;
	}

	if (key == '2') {
		feed = 0.010;
		kill = 0.047;
	}

	if (key == '3') {
		feed = 0.014;
		kill = 0.039;
	}

	if (key == '4') {
		feed = 0.030;
		kill = 0.055;
	}

	if (key == ' ') {

		for (int i = 0; i < 20; i++)
		{

			float x = ofRandom(ofGetWidth());
			float y = ofRandom(ofGetHeight());
			float size = ofRandom(4, 80);

			pingPong.dst->begin();
			ofClear(0);
			ofSetColor(255);
			ofDrawCircle(x, y, size);
			pingPong.src->draw(0, 0);
			pingPong.dst->end();
			pingPong.swap();

		}

	}

	if (key == 'r') {

		pingPong.dst->begin();
		ofClear(0);
		ofSetColor(0);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		pingPong.src->draw(0, 0);
		pingPong.dst->end();
		pingPong.swap();

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

	pingPong.dst->begin();
	ofClear(0);
	ofSetColor(255);
	ofDrawCircle(x, y, 30);
	pingPong.src->draw(0, 0);
	pingPong.dst->end();

	pingPong.swap();

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
