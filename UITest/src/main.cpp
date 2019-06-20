#include "ofMain.h"
#include "ofApp.h"

int FULL_HD_WIDTH = 1920;
int FULL_HD_HEIGHT = 1080;

int SCREEN_WIDTH = 1440;
int SCREEN_HEIGHT = 900;

int GOKKAN_WIDTH = 1280;
int GOKKAN_HEIGHT = 800;

//========================================================================
int main( ){
    
    ofSetupOpenGL(GOKKAN_WIDTH, GOKKAN_HEIGHT, OF_WINDOW);
	ofRunApp(new ofApp());

}
