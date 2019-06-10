//
//  SierpinskiGasket.hpp
//  180529a
//
//  Created by nojimakosuke on 2018/05/30.
//

#ifndef SierpinskiGasket_hpp
#define SierpinskiGasket_hpp

#include <stdio.h>
#include "ofMain.h"

class SierpinskiGasket {
    
public:
    void setup();
    void update();
    void draw();
    void reset();
    
private:
    int generation = 0;
    int frame = 0;
    int maxGeneration = 8;
    
    ofMesh mesh;
    
};

#endif /* SierpinskiGasket_hpp */
