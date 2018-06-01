#include "ofApp.h"

void ofApp::setup(){
    
    // video
    // video.load("source.mp4");
    // video.play();
    
    // camera
    // ofBackground(0, 0, 0);
    // ofSetFrameRate(30);
    // ofSetWindowTitle("Chroma Key Test.");
    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    grabber.setDeviceID(1);
    
    shader.load("shader/chromaKey");
}

void ofApp::update(){
    
    // video
    // video.update();
    
    // camera
    grabber.update();
}

void ofApp::draw(){
    
    // 背景色を描画（グラデーション）
    // ofBackgroundGradient(ofColor(128), ofColor(31), OF_GRADIENT_LINEAR);
    // 黒い部分を赤くする
    ofBackground(255, 0, 127);
    
    // 閾値を指定
    float difference = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
 
    // シェーダーに描画色と閾値と送る
    shader.begin();
    shader.setUniform3f("chromaKeyColor", ofVec3f(0.0, 0.0, 0.0));
    shader.setUniform1f("difference", difference);
    
    // video
    // video.draw(0, 0);
    
    // camera
    grabber.draw(0, 0);
    
    shader.end();
    
}
