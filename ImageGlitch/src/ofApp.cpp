#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
    
    quality = OF_IMAGE_QUALITY_WORST;
    
    reset();
    
}

//--------------------------------------------------------------
void ofApp::reset(){

    img.load("pierrot_" + ofToString(image_count) + ".jpg");
    
//    image_count = image_count + 1;
//    if(image_count > IMAGE_LENGTH){
//        image_count = 1;
//    }
    
    image_count = ofRandom(1, IMAGE_LENGTH);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 1; i++){
        
        string compressedFilename = "compressed.jpg";
        
        img.save(compressedFilename, quality);
        
        ofBuffer file = ofBufferFromFile(compressedFilename);
        int fileSize = file.size();
        char * buffer = file.getData();
        
        int whichByte = (int) ofRandom(fileSize);
        int whichBit = ofRandom(8);
        char bitMask = 1 << whichBit;
        buffer[whichByte] |= bitMask;
        
        ofBufferToFile(compressedFilename, file);
        img.load(compressedFilename);
        
        count = count + 1;
        if(count > 120){
            reset();
            count = 0;
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    img.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        reset();
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
