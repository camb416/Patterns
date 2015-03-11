#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //float radius = 200;
    
    // GUI Stuff
    // we add this listener before setting up so the initial circle resolution is correct
  //  circleResolution.addListener(this, &ofApp::circleResolutionChanged);
    ringButton.addListener(this,&ofApp::regenerate);
    
    gui.setup(); // most of the time you don't need a name
  //  gui.add(radius.setup( "radius", 140, 10, 300 ));
    gui.add(center.setup("center",ofVec2f(ofGetWidth()*.5,ofGetHeight()*.5),ofVec2f(0,0),ofVec2f(ofGetWidth(),ofGetHeight())));
    gui.add(color.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    gui.add(generations.setup("generations", 6, 0, 10));
    gui.add(twoCircles.setup("two circles"));
    gui.add(ringButton.setup("regenerate"));
    gui.add(screenSize.setup("screen size", ""));
    
    gui.add(radius.setup("initial radius",100,1,300));
    gui.add(spokes.setup("spokes",16,1,128));
    
    gui.add(cDivisor.setup("children divisor",2.0f,0.5f,4.0f));
    gui.add(rDivisor.setup("radius divisor",2.0f,0.5f,4.0f));
    gui.add(sDivisor.setup("spread divisor",2.0f,0.5f,4.0f));
    
    
    
    gui.loadFromFile("settings.xml");
    
    bHide = true;
    
    regenerate();

}

void ofApp::regenerate(){
    lines.clear();
       generateFan(ofPoint(ofGetWidth()/2,ofGetHeight()/2),0, spokes,generations,radius,TWO_PI);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(color);
    for(int i=0;i<lines.size();i++){
        lines.at(i)->draw();
    }
    
    if( bHide ){
        gui.draw();
    }
}
void ofApp::renderPostScript(){
    // declare vector graphics file
    // open vector file
    vectorFile.beginEPS("test.ps");
    vectorFile.noFill();
    vectorFile.setColor(0,0,0);
    
     for(int i=0;i<lines.size();i++){
    // lines.at(i)->drawPostscript(f);
         ofPoint a = lines.at(i)->p1;
         ofPoint b = lines.at(i)->p2;
         vectorFile.line(a.x,a.y,b.x,b.y);
     }
    vectorFile.endEPS();
}
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
            generateFan(ofPoint(x2,y2), thisAngle, _children/cDivisor, _generations-1,_radius/rDivisor,_spread/sDivisor);
        }
        CLine * l = new CLine(x1,y1,x2,y2);
        lines.push_back(l);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch(key){
            case 'v':
            case 'V':
            renderPostScript();
            break;
    }
    
    if( key == 'h' ){
        bHide = !bHide;
    }
    if(key == 's') {
        gui.saveToFile("settings.xml");
    }
    if(key == 'l') {
        gui.loadFromFile("settings.xml");
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
