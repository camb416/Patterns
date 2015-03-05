#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float radius = 200;
    /*
    for(int i=0;i<16;i++){
        float x1 = ofGetWidth()/2;
        float y1 = ofGetHeight()/2;
        float angle = PI*2/16*i;
        float x2 = x1+cos(angle)*radius;
        float y2 = y1+sin(angle)*radius;
        CLine * l = new CLine(x1,y1,x2,y2);
        lines.push_back(l);
    }
     */
    generateFan(ofPoint(ofGetWidth()/2,ofGetHeight()/2),0, 64,4,200,TWO_PI);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(0,0,0,16);
    for(int i=0;i<lines.size();i++){
        lines.at(i)->draw();
    }
}
//void ofApp::renderPostScript(){
    
//}
void ofApp::generateFan(ofPoint _p, float _angle, int _children, int _generations, float _radius, float _spread){
    for(int i=0;i<_children;i++){
        float x1 = _p.x;
        float y1 = _p.y;
        float compensator = -1.0f;
        if(_spread>=TWO_PI){
            compensator = 0.0f;
        }
        float thisAngle = (float)i*(_spread/((float)_children+compensator))+_angle-_spread/2.0f;
        float x2 = x1+cos(thisAngle)*_radius;
        float y2 = y1+sin(thisAngle)*_radius;
        if(_generations>0){
            generateFan(ofPoint(x2,y2), thisAngle, _children/2.0f, _generations-1,_radius/1.5f,_spread/1.5f);
        }
        CLine * l = new CLine(x1,y1,x2,y2);
        lines.push_back(l);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
// declare vector graphics file
// open vector file
    for(int i=0;i<lines.size();i++){
       // lines.at(i)->drawPostscript(f);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
