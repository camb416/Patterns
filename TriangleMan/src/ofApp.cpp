#include "ofApp.h"

#define NUM_COLS 40
#define NUM_ROWS 40
#define SHAPE_SIZE 10
#define NUM_SIDES 3
#define FREQ 25
#define OFFSET FREQ/2

vector<Pgon*> polys;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    outputCount = 0;
    initGeometry();

}

void ofApp::initGeometry(){
    ofColor  colors [3] = {ofColor(128,212,0),ofColor(128,128,255),ofColor(0,255,64)};
    polys.clear();
    
    int shapeCount = 0;
    for(int i=0;i<NUM_ROWS;i++){
        for(int j=0;j<NUM_COLS;j++){
            //Pgon * p = new Pgon(100+FREQ*j+(i%2)*OFFSET,100+FREQ*i,SHAPE_SIZE,(shapeCount)%3+3);
            
            int the_x = 100+FREQ*j+(i%2)*OFFSET;
            int the_y = 100+FREQ*i;
            int the_size = SHAPE_SIZE;
            // int the_sides = (shapeCount)%3+3;
            int the_sides = NUM_SIDES;
            float the_angle = shapeCount/10.0f;
            
            Pgon * p = new Pgon(the_x,the_y,the_size,the_sides,the_angle);
            
            //p->setColor(colors[(shapeCount)%3]);
            p->setColor(colors[(int)round(ofRandom(2))]);
            // p->setColor(ofColor(0,0,0,16));
            shapeCount++;
            polys.push_back(p);
            
        }
        // Poly * thisPoly = new Poly(100,100,20);
        //Pgon * p = new Pgon(100,100,20);
        //vector<Pgon*> polys;
        //  testVec.push_back(1);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofEnableAlphaBlending();
 for(int i=0;i<polys.size();i++){
        polys.at(i)->draw();
    
 }
}

void ofApp::saveFile(int file_int){
    ofxVectorGraphics output;
    string fileName = "output_" + ofToString(file_int) + ".ps";
    output.beginEPS(fileName);
    output.setColor(0x000000);
    output.fill();
    
    
    
    //set number of sides based on mouse position
    // int numSteps = ( (float)mouseX / ofGetWidth() )* 12.0;
    
    //make sure we don't go bellow 3 sides
    // numSteps = MAX(3, numSteps);
    
    
    //  float step		= TWO_PI / (numSteps);
    //  float angle		= 0.0;
    //   float cenX		= 110;
    //   float cenY		= 430;
    //   float radius	= 50;
    
    for(int i = 0; i < polys.size(); i++){
        //      float rx = cenX + cos(angle) * radius;
        //    float ry = cenY + sin(angle) * radius;
        output.beginShape();
        output.setColor(polys.at(i)->c.getHex());
        output.fill();
        for(int j = 0; j < polys.at(i)->s; j++){
            output.polyVertex(polys.at(i)->pts[j].x,polys.at(i)->pts[j].y);
        }
        output.endShape(true);
        //      angle += step;
    }
    
    
    
    output.endEPS();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
            case 's':
            case 'S':
            
            saveFile(outputCount++);
            initGeometry();
            
            break;
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
