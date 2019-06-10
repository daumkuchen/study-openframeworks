#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    srcImage.load("images/image.jpg");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ShowImage si;
    
    // before
    // 毎回画像インスタンスを作成するとメモリリークの元になるのでNG
    // si.image = srcImage;
    
    // after
    // ポインターでデータを参照
    si.image = &srcImage;
    
    showImages.push_back(si);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 255, 255);
    for (int i = 0; i < showImages.size(); i++) {
        showImages[i].draw();
    }
    
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
