#pragma once
#include "ofMain.h"

class ShowImage{
    
public:
    
    void draw();
    
    // before
    // ofImage image;
    // after
    ofImage *image;
    
    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());
    float size = 40;
    
};
