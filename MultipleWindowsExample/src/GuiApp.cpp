#include "GuiApp.h"

void GuiApp::setup(){
    
//    parameters.setName("parameters");
//    parameters.add(radius.set("radius", 50, 1, 100));
//    parameters.add(color.set("color", 100, ofColor(0, 0), 255));
//    gui.setup(parameters);
//    ofBackground(0);
//    ofSetVerticalSync(false);
    
    layer.load("video/video.mp4");
    layer.play();
    fbo.allocate(1280, 720, GL_RGB32F_ARB);
    
}

void GuiApp::update(){
    
    layer.update();
    fbo.begin();
    layer.draw(0, 0, 1280, 720);
    fbo.end();
    
}

void GuiApp::draw(){
    
//    gui.draw();
    
    fbo.draw(0, 0, 128, 72);
    
}
