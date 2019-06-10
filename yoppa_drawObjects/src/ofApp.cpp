#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
}

void ofApp::update(){
    box2d.update();
}

void ofApp::draw(){
    ofFill();
    ofSetLineWidth(1.0);
    
    //draw circles
    ofSetColor(31, 127, 255);
    for(int i=0; i<circles .size(); i++) {
        circles[i].get()->draw();
    }
    
    //draw boxes
    ofSetColor(255, 127, 31);
    for(int i=0; i<boxes .size(); i++) {
        boxes[i].get()->draw();
    }
    
    //draw edge
    ofNoFill();
    ofSetLineWidth(2.0);
    ofSetColor(255);
    for (int i=0; i<edges.size(); i++) {
        edges[i].get()->draw();
    }
}

void ofApp::keyPressed(int key){
    if(key == 'c') {
        float r = ofRandom(4, 20);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        
    }
    if(key == 'b') {
        float w = ofRandom(4, 20);
        float h = ofRandom(4, 20);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
        boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
    }
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    //add vertex for drawing
    lines.back().addVertex(x, y);
}

void ofApp::mousePressed(int x, int y, int button){
    lines.push_back(ofPolyline());
    lines.back().addVertex(x, y);
}

void ofApp::mouseReleased(int x, int y, int button){
    //create new edge
    shared_ptr <ofxBox2dEdge> edge = shared_ptr<ofxBox2dEdge>(new ofxBox2dEdge);
    //simplity the drawed lines
    lines.back().simplify();
    //generate edge from lines
    for (int i=0; i<lines.back().size(); i++) {
        edge.get()->addVertex(lines.back()[i]);
    }
    //add edge to box2d world
    edge.get()->create(box2d.getWorld());
    edges.push_back(edge);
}

void ofApp::mouseEntered(int x, int y){
    
}

void ofApp::mouseExited(int x, int y){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
