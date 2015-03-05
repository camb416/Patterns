//
//  Poly.h
//  TriangleMan
//
//  Created by Cameron Browning on 3/2/15.
//
//

#ifndef __TriangleMan__Poly__
#define __TriangleMan__Poly__

#include "ofMain.h"
#include <stdio.h>

class Pgon{
public:
    Pgon(int _x,int _y, int _r);
    Pgon(int _x,int _y, int _r,int _s);
    Pgon(int _x,int _y, int _r,int _s, float _a);
    Pgon();
    ~Pgon();
    float x;
    float y;
    float r;
    void draw();
    
    ofPoint * pts;
    int s;
    
    ofColor c;
    void setColor(ofColor _c);
    
};

#endif /* defined(__TriangleMan__Poly__) */
