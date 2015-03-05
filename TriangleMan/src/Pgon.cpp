//
//  Poly.cpp
//  TriangleMan
//
//  Created by Cameron Browning on 3/2/15.
//
//

#include "Pgon.h"
#include "ofMain.h"

Pgon::Pgon(){
    x = 100;
    y = 100;
    r = 50;
    c = ofColor(0);
}
Pgon::~Pgon(){
    // empty destructor
}

Pgon::Pgon(int _x,int _y, int _r){
    Pgon(_x,_y,_r,3);
}
Pgon::Pgon(int _x,int _y, int _r, int _s){
    Pgon(_x,_y,_r,_s,0.0f);
}

Pgon::Pgon(int _x,int _y, int _r, int _s, float _a){
   x = _x;
   y = _y;
   r = _r;
    s = _s;
    pts = new ofPoint[s];
    for(int i=0;i<s;i++){
        float a = TWO_PI/(float)s;
        pts[i] = ofPoint(x+r*cos(i*a+_a),y+sin(i*a+_a)*r);
        ofLog() << pts[i].x << ", " << pts[i].y;
    }
    c = ofColor(0);
    
    
}
void Pgon::draw(){
    ofSetColor(c);
    //ofSetCircleResolution(3);
    //ofCircle(x, y, r);
    ofBeginShape();
    for(int i=0;i<s;i++){
    ofVertex(pts[i].x,pts[i].y);
    }
    ofEndShape(true);
}

void Pgon::setColor(ofColor _c){
    c = _c;
}