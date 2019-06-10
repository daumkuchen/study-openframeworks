#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    //    ofSetupOpenGL(1024,768,OF_WINDOW);
    //    ofRunApp(new ofApp());
    
    ofGLFWWindowSettings settings;
    settings.setSize(200, 200);
    settings.resizable = false;
    
    for (int i = 0; i < 32; i++) {
        
        shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
        shared_ptr<ofApp> window_app(new ofApp);
        ofRunApp(window, window_app);
    }
    
    ofRunMainLoop();
    
}
