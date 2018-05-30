//
//  SierpinskiGasket.cpp
//  001
//
//  Created by nojimakosuke on 2018/05/29.
//

#include "SierpinskiGasket.hpp"

void SierpinskiGasket::setup(){
    reset();
}

void SierpinskiGasket::update(){
    frame++;
    
    if(frame % 30 != 0) return;
    if(generation >= maxGeneration) return;
    
    for(int i = 0; i < 6 * mesh.getNumVertices()/3; i++){
        mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
    }
    
    for(int i = mesh.getNumVertices() / 3 - 1; i >= 0 ; i--){
        ofPoint p1 = (mesh.getVertices().at(i * 3) + mesh.getVertices().at(i * 3 + 1))/ 2.0;
        ofPoint p2 = (mesh.getVertices().at(i * 3) + mesh.getVertices().at(i * 3 + 2))/ 2.0;
        ofPoint p3 = (mesh.getVertices().at(i * 3 + 1) + mesh.getVertices().at(i * 3 + 2))/ 2.0;
        
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 2, p2);
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 2, p3);
        
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 1, p1);
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 1, p3);
        
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 1, p1);
        mesh.getVertices().insert(mesh.getVertices().begin() + i * 3 + 1, p2);
    }
    generation++;
}

void SierpinskiGasket::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, 50);
    mesh.draw();
    ofPopMatrix();
}

void SierpinskiGasket::reset(){
    generation = 0;
    frame = 0;
    mesh.clear();
    mesh.addVertex(ofPoint(-400, 0));
    mesh.addVertex(ofPoint( 400, 0));
    mesh.addVertex(ofPoint(0, 400 * sqrt(3.0)));
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    for(int i = 0; i < 3; i++){
        mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
    }
}
