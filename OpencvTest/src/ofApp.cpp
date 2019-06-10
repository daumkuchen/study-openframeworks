#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    // face tracker
//    ofSetVerticalSync(true);
//    ofSetFrameRate(120);
//    finder.setup("haarcascade_frontalface_default.xml");
//    finder.setPreset(ObjectFinder::Fast);
//    finder.getTracker().setSmoothingRate(.3);
//    cam.setup(640, 480);
//    sunglasses.load("sunglasses.png");
//    ofEnableAlphaBlending();
    
    // face zoom
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    objectFinder.setup(ofToDataPath("haarcascade_frontalface_default.xml"));
    objectFinder.setPreset(ObjectFinder::Fast);
    cam.setup(640, 480);
    cropped.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // face tracker
//    cam.update();
//    if(cam.isFrameNew()) {
//        finder.update(cam);
//    }
    
    // face zoom
    cam.update();
    if(cam.isFrameNew()) {
        objectFinder.update(cam);
        if(objectFinder.size() > 0) {
            cv::Rect roi = toCv(objectFinder.getObject(0));
            Mat camMat = toCv(cam);
            Mat croppedCamMat(camMat, roi);
            resize(croppedCamMat, cropped);
            cropped.update();
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // face tracker
//    cam.draw(0, 0);
//    for(int i = 0; i < finder.size(); i++) {
//        ofRectangle object = finder.getObjectSmoothed(i);
//        sunglasses.setAnchorPercent(.5, .5);
//        float scaleAmount = .85 * object.width / sunglasses.getWidth();
//        ofPushMatrix();
//        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
//        ofScale(scaleAmount, scaleAmount);
//        sunglasses.draw(0, 0);
//        ofPopMatrix();
//        ofPushMatrix();
//        ofTranslate(object.getPosition());
//        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
//        ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
//        ofPopMatrix();
//    }
    
    // face zoom
    cropped.draw(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
