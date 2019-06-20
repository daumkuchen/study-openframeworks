#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
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
    
    void drawRect(
                  string text,
                  float posx,
                  float posy,
                  float sizex,
                  float sizey,
                  ofColor color,
                  bool border);
    
    void drawWireFrame();
    
    ofTrueTypeFont font;
    
    float one_half = 0.5;
    float one_third = 0.3333;
    float one_fourth = 0.25;
    
    int WIDTH = 1280;
    int HEIGHT = 800;
    int padding = 8;
    int num_clip = 8;
    
};
