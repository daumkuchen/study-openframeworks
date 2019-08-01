#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetBackgroundColor(0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	shader.load("shader/shader");

	ofDisableArbTex();

	img.load("images/mona_square.jpg");
	//img.load("images/mona_default.jpg");

	pos = ofVec3f(0.0, 0.0, 0.0);

	ofVec2f imgSize = ofVec2f(img.getWidth(), img.getHeight());

	vboMesh.addVertex(ofVec3f(-imgSize.x / 2.0, -imgSize.y / 2.0, 0.0));
	vboMesh.addVertex(ofVec3f(imgSize.x / 2.0, -imgSize.y / 2.0, 0.0));
	vboMesh.addVertex(ofVec3f(imgSize.x / 2.0, imgSize.y / 2.0, 0.0));
	vboMesh.addVertex(ofVec3f(-imgSize.x / 2.0, imgSize.y / 2.0, 0.0));

	vboMesh.addIndex(0);
	vboMesh.addIndex(1);
	vboMesh.addIndex(2);
	vboMesh.addIndex(2);
	vboMesh.addIndex(3);
	vboMesh.addIndex(0);

	//ofDisableArbTex()�̏ꍇ
	vboMesh.addTexCoord(ofVec2f(0.0, 4.0));
	vboMesh.addTexCoord(ofVec2f(4.0, 4.0));
	vboMesh.addTexCoord(ofVec2f(4.0, 0.0));
	vboMesh.addTexCoord(ofVec2f(0.0, 0.0));

}

//--------------------------------------------------------------
void ofApp::update() {

	//ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw() {

	glEnable(GL_TEXTURE_2D);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClear(GL_COLOR_BUFFER_![bandicam 2019 - 04 - 30 18 - 47 - 02 - 434.jpg](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/184790/9a9de613-161b-ced0-81d1-73a7857b4e7b.jpeg)
	//BIT | GL_DEPTH_BUFFER_BIT);

	cam.begin();
	cam.lookAt(ofVec3f(0.0, 0.0, 0.0), ofVec3f(0.0, 1.0, 0.0));
	img.getTexture().bind();


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	shader.begin();

	ofMatrix4x4 modelMatrix;
	ofMatrix4x4 viewMatrix;
	viewMatrix = ofGetCurrentViewMatrix();
	ofMatrix4x4 projectionMatrix;
	projectionMatrix = cam.getProjectionMatrix();
	ofMatrix4x4 mvpMatrix;
	mvpMatrix = modelMatrix * viewMatrix * projectionMatrix;

	shader.setUniformMatrix4f("model", modelMatrix);
	shader.setUniformMatrix4f("view", viewMatrix);
	shader.setUniformMatrix4f("projection", projectionMatrix);
	shader.setUniformMatrix4f("mvp", mvpMatrix);
	shader.setUniformTexture("tex0", img.getTexture(), 0);

	//vboMesh = plane.getMesh();
	for (int j = 0; j < vboMesh.getVertices().size(); j++) {
		vboMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
	}

	vboMesh.draw();
	shader.end();

	img.getTexture().unbind();
	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
