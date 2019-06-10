#pragma once

#include "ofMain.h"

#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void setRandom();
    void setParam();
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
    
    ofMesh mesh;
    
    float point_size = 1;
    int poiont_num = 50000;
    
    ofVec3f points[50000];
    
    ofxPanel gui;
    ofxFloatSlider a;
    ofxFloatSlider b;
    ofxFloatSlider c;
    ofxFloatSlider d;
    ofxFloatSlider e;
    ofxFloatSlider f;
    ofxColorSlider color;
    
    float pa;
    float pb;
    float pc;
    float pd;
    float pe;
    float pf;
    
    int image_count = 0;
    int frame_count = 0;
    
    ofImage image;
    
    ofEasyCam cam;
    int axis_y;
    
};
