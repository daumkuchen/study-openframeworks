#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // ofSetVerticalSync(false);
    // ofSetFrameRate(30);
    
    const int resolution = 128;
    mc.setup(resolution, resolution, resolution);
    
    gui.setup();
    gui.add(fpsDisp.setup("Fps", ""));
    
    auto strResol = ofToString(resolution);
    gui.add(resolutionDisp.setup("resolution", strResol + "x" + strResol + "x" + strResol));
    
    gui.add(threshold.setup("threshold", 0.5f, 0.02f, 0.98f));
    gui.add(speed.setup("speed", 0.5f, 0.01f, 2.0f));
    gui.add(scale.setup("scale", 1.15f, 0.75f, 2.0f));
    
}

//--------------------------------------------------------------
void ofApp::update(){

    fpsDisp = ofToString(ofGetFrameRate());
    
    mc.updateField(ofGetElapsedTimef() * speed, scale);
    mc.update(threshold);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor(15, 16, 37), ofColor(11, 11, 10));
    
    cam.begin();
    ofPushMatrix();
    ofScale(300.0f, 300.0f, 300.0f);
    mc.draw();
    ofPopMatrix();
    cam.end();
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
            
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
    
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
