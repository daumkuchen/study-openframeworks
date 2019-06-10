#include "ofMain.h"

#include "ofApp.h"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	
    ofGLFWWindowSettings settings;
    
    settings.setSize(600, 600);
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.setSize(300, 300);
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    
    // @@@
    mainApp -> gui = guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();

}
