#include "ofApp.h"

#define A_LEN 17
#define B_LEN 23
#define C_LEN 5

#define POLYHEIGHT 100

#define A_W 10
#define B_W 17
#define C_W 23

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0;i<A_LEN;i++){
        a.push_back(ofPoint(ofGetWidth()/2-(A_LEN*A_W/2)+i*A_W,ofGetHeight()/2-POLYHEIGHT));
    }
    for(int i=0;i<B_LEN;i++){
        b.push_back(ofPoint(ofGetWidth()/2-(B_LEN*B_W/2)+i*B_W,ofGetHeight()/2));
    }
    for(int i=0;i<C_LEN;i++){
        c.push_back(ofPoint(ofGetWidth()/2-(C_LEN*C_W/2)+i*C_W,ofGetHeight()/2+POLYHEIGHT));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    for(int i=0;i<a.size();i++){
        ofCircle(a.at(i),2);
    }
    for(int i=0;i<b.size();i++){
        ofCircle(b.at(i),2);
    }
    for(int i=0;i<c.size();i++){
        ofCircle(c.at(i),2);
    }
    
   
    for(int i=1;i<b.size();i++){
    
        // get midpoint
        ofPoint m = (b.at(i) - b.at(i-1))/2+b.at(i-1);
        ofSetColor(255,0,0);
        ofCircle(m,2);
        
        // get nearest of a to midpoint
        float nearestDist = 99999;
        int nearID = -1;
        for(int j=0;j<a.size();j++){
            float thisDist = ofDist(a.at(j).x,a.at(j).y,b.at(i).x,b.at(i).y);
            if(thisDist<nearestDist){
                nearID = j;
                nearestDist = thisDist;
            }
        }
        ofSetColor(0,255,0);
        ofLine(b.at(i-1),a.at(nearID));
        ofLine(b.at(i),a.at(nearID));
        ofSetColor(0);
        ofLine(b.at(i-1),b.at(i));
        
        // get nearest of c to midpoint
        nearestDist = 99999; //reuse these
        nearID = -1;
        for(int j=0;j<c.size();j++){
            float thisDist = ofDist(c.at(j).x,c.at(j).y,b.at(i).x,b.at(i).y);
            if(thisDist<nearestDist){
                nearID = j;
                nearestDist = thisDist;
            }
        }
        ofSetColor(0,0,255);
        ofLine(b.at(i-1),c.at(nearID));
        ofLine(b.at(i),c.at(nearID));
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
