#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("station.mp4");
    // player.setLoopState(OF_LOOP_NORMAL);
    player.play();
    
    texture.allocate(window_width, window_height, GL_RGB);
    texpixels = new unsigned char [window_width * window_height * 3];
    
}

//--------------------------------------------------------------
void ofApp::update(){

    player.update();
    
    newFrame = player.isFrameNew();
    if(newFrame){
        vidpixels = player.getPixels().getData();
        for (int y=0; y<window_height; y++){
            unsigned char r, g, b;
            getPixel(video_slice_x, y, &r, &g, &b, video_width, vidpixels);
            setPixel(draw_position_x, y, r, g, b, window_width, texpixels);
        }
        texture.loadData(texpixels, window_width, window_height, GL_RGB);

        draw_position_x++;
        if (draw_position_x >= window_width) {
            OF_EXIT_APP(0);
        }
        newFrame = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0, 0, 0);
    texture.draw(0, 0);
    
    // player.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
}

//--------------------------------------------------------------
void ofApp::setPixel(int horizontal,int vertical,unsigned char R,unsigned char G,
                                  unsigned char B,int w, unsigned char pixels[]){
    int thisPixel;
    thisPixel = 3*(w * vertical +horizontal);
    pixels[thisPixel]=R;
    pixels[thisPixel+1]=G;
    pixels[thisPixel+2]=B;
}

//--------------------------------------------------------------
void ofApp::getPixel(int horizontal,int vertical,unsigned char* R,unsigned char* G,
                                  unsigned char* B,int w, unsigned char pixels[]){
    int thisPixel;
    thisPixel = 3*(w * vertical +horizontal);
    *R= pixels[thisPixel];
    *G= pixels[thisPixel+1];
    *B= pixels[thisPixel+2];
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
