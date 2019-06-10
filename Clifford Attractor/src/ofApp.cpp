#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // ofSetBackgroundAuto(false);
    ofBackground(0);
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    ofColor initColor = ofColor(255, 255, 255, 255);
    ofColor minColor = ofColor(0, 0, 0, 0);
    ofColor maxColor = ofColor(255, 255, 255, 255);
    
    // gui.setup();
    // gui.add(a.setup("a", 0, 1, 2));
    // gui.add(b.setup("b", 0, 1, 2));
    // gui.add(c.setup("c", 0, 1, 2));
    // gui.add(d.setup("d", 0, 1, 2));
    // gui.add(d.setup("e", 0, 1, 2));
    // gui.add(d.setup("f", 0, 1, 2));
    // gui.add(color.setup("color", initColor, minColor, maxColor));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    // setParam();
    
    cam.begin();
    
    ofPushMatrix();
    
    // ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    // ofRotateXDeg(axis_y++);
    // ofRotateYDeg(axis_y++);
    // ofRotateZDeg(axis_y++);
    
    mesh.clear();
    
    float prev_x = 0;
    float prev_y = 0;
    float prev_z = 0;
    
    for(int i = 0; i < poiont_num; i++){
        
        // float x = sin(pa * prev_y) - cos(pb * prev_x);
        // float y = sin(pc * prev_z) - cos(pd * prev_y);
        // float z = sin(pe * prev_x) - cos(pf * prev_z);
        float x = sin(pa * prev_y) - cos(pb * prev_x);
        float y = sin(pc * prev_x) - cos(pd * prev_y);
        
        points[i].x = x * 180;
        points[i].y = y * 180;
        // points[i].z = z * 180;
        
        mesh.addVertex(ofVec3f(points[i].x, points[i].y, 0));
        
        prev_x = x;
        prev_y = y;
        // prev_z = z;

//        mesh.addColor(ofColor(125, 0, 0));
//        mesh.addColor(ofColor(125, 0, 0));
//        mesh.addColor(ofColor(0, 125, 0));
//        mesh.addColor(ofColor(0, 0, 125));
        
        mesh.addColor(ofColor(55, 55, 55));
        
        // ofDrawLine(points[i], points[i + 1]);

    }
    
    glPointSize(point_size);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.draw();
    
    ofPopMatrix();
    
    cam.end();
    
    // gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::setRandom(){
    
    pa = ofRandom(-2.5, 2.5);
    pb = ofRandom(-2.5, 2.5);
    pc = ofRandom(-2.5, 2.5);
    pd = ofRandom(-2.5, 2.5);
    pe = ofRandom(-2.5, 2.5);
    pf = ofRandom(-2.5, 2.5);
    
}

//--------------------------------------------------------------
void ofApp::setParam(){
    
    frame_count += 1;
    
    pa = 1.9 - frame_count / 4000.0;
    pb = 0.3 + frame_count / 500.0;
    pc = 1.9 - frame_count / 3000.0;
    pd = 0.3 + frame_count / 500.0;
    pe = 1.9 - frame_count / 1000.0;
    pf = 0.3 + frame_count / 500.0;
    
}

//--------------------------------------------------------------
void ofApp::reset(){
    
    frame_count = 0;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        
        setRandom();

        image_count += 1;
        image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        image.save("screenshot_" + ofToString(image_count) + ".jpg");
        
        // reset();
        
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
