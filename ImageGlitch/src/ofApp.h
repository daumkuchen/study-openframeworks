#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    
    // https://www.atlasofplaces.com/cinema/pierrot-le-fou/
    
    void setup();
    void update();
    void draw();
    void reset();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage img;
    ofImageQualityType quality;
    
    int count = 0;
    int image_count = 1;
    int IMAGE_LENGTH = 25;
    
};
