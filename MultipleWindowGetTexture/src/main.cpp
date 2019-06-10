#include "ofMain.h"

#include "ofApp.h"

//========================================================================
int main(){
    
    ofGLFWWindowSettings settings;
    
    // main window
    settings.setSize(600, 600);
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    // gui window
    settings.setSize(300, 300);
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    guiWindow->setVerticalSync(false);
    
    // generate app
    shared_ptr<ofApp> mainApp(new ofApp);
    
    // eventの登録?
    mainApp -> setupGui();
    ofAddListener(guiWindow -> events().draw, mainApp.get(), &ofApp::drawGui);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
};
