//
//  CLine.cpp
//  vectorTree
//
//  Created by Cameron Browning on 3/5/15.
//
//

#include <stdio.h>
#include "CLine.h"

CLine::CLine(float _x1, float _y1, float _x2, float _y2){
    // constructor
    p1 = ofPoint(_x1, _y1);
    p2 = ofPoint(_x2, _y2);
}

void CLine::draw(){
    // draw to screen
    ofLine(p1,p2);
}
void CLine::drawPostScript(int _file){
    // draw to postscript
}