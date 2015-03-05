//
//  CLine.h
//  vectorTree
//
//  Created by Cameron Browning on 3/5/15.
//
//

#ifndef vectorTree_CLine_h
#define vectorTree_CLine_h

#include "ofMain.h"

class CLine{
public:
    ofPoint p1;
    ofPoint p2;
    CLine(float _x1,float _y1, float _x2, float _y2);
    void draw();
    void drawPostScript(int _file);
    
private:
    
};

#endif
