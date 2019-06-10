#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    fft.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    fft.update();
    
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, 1);
    std::cout << lowValue << std::endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    fft.drawBars();
    fft.drawDebug();
    
    ofNoFill();
    ofDrawRectangle(824, 0, 200, 200);
    ofDrawRectangle(824, 200, 200, 200);
    ofDrawRectangle(824, 400, 200, 200);
    ofDrawRectangle(824, 600, 200, 200);
    
    fft.drawHistoryGraph(ofPoint(824, 0), LOW);
    fft.drawHistoryGraph(ofPoint(824, 200), MID);
    fft.drawHistoryGraph(ofPoint(824, 400), HIGH);
    fft.drawHistoryGraph(ofPoint(824, 600), MAXSOUND);
    
    ofDrawBitmapString("LOW",850,20);
    ofDrawBitmapString("HIGH",850,420);
    ofDrawBitmapString("MID",850,220);
    ofDrawBitmapString("MAX VOLUME",850,620);
    
    ofSetColor(0);
    ofDrawBitmapString("Press 'r' or 'q' to toggle normalization of values", 20,320);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key=='q'){
        fft.setVolumeRange(100);
        fft.setNormalize(false);
    }
    
    if(key=='r'){
        fft.setNormalize(true);
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
