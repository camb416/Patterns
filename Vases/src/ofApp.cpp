#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    

    
    drawMode = 0;
   
    int height = 5;
    int width = 5;
    for (int y = 0; y < height; y++){
        for (int x = 0; x<width; x++){
            mesh.addVertex(ofPoint(x*20-40,y*20,0)); // make a new vertex
            mesh.addColor(ofFloatColor(0,0,0));  // add a color at that vertex
        }
    }
    
    // now it's important to make sure that each vertex is correctly connected with the
    // other vertices around it. This is done using indices, which you can set up like so:
    for (int y = 0; y<height-1; y++){
        for (int x=0; x<width-1; x++){
            mesh.addIndex(x+y*width);               // 0
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex(x+(y+1)*width);           // 10
            
            mesh.addIndex((x+1)+y*width);           // 1
            mesh.addIndex((x+1)+(y+1)*width);       // 11
            mesh.addIndex(x+(y+1)*width);           // 10
        }
    }

    // bottom triangle
    mesh2.addVertex(ofPoint(0,0,0));
    mesh2.addColor(ofFloatColor(0,0,0));

    mesh2.addVertex(ofPoint(10,0,0));
    mesh2.addColor(ofFloatColor(0,0,0));

    mesh2.addVertex(ofPoint(0,0,10));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    //top triangle
    mesh2.addVertex(ofPoint(-10,20,-10));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    mesh2.addVertex(ofPoint(20,20,-10));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    mesh2.addVertex(ofPoint(-10,20,20));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    // bottom triangle
    mesh2.addVertex(ofPoint(0,50,0));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    mesh2.addVertex(ofPoint(10,50,0));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    mesh2.addVertex(ofPoint(0,50,10));
    mesh2.addColor(ofFloatColor(0,0,0));
    
    
    
    // bottom
    mesh2.addIndex(0);
    mesh2.addIndex(1);
    mesh2.addIndex(2);
    


 
    
    mesh2.addIndex(0);
    mesh2.addIndex(3);
    mesh2.addIndex(1);
    
    mesh2.addIndex(3);
    mesh2.addIndex(1);
    mesh2.addIndex(4);
    
    mesh2.addIndex(1);
    mesh2.addIndex(4);
    mesh2.addIndex(2);
    
    mesh2.addIndex(2);
    mesh2.addIndex(4);
    mesh2.addIndex(5);

    mesh2.addIndex(0);
    mesh2.addIndex(3);
    mesh2.addIndex(2);
    
    mesh2.addIndex(2);
    mesh2.addIndex(3);
    mesh2.addIndex(5);
    
    
    
    
    mesh2.addIndex(3);
    mesh2.addIndex(4);
    mesh2.addIndex(6);
    
    mesh2.addIndex(4);
    mesh2.addIndex(6);
    mesh2.addIndex(7);
    
    mesh2.addIndex(4);
    mesh2.addIndex(7);
    mesh2.addIndex(5);
    
    mesh2.addIndex(5);
    mesh2.addIndex(7);
    mesh2.addIndex(8);
    
    mesh2.addIndex(3);
    mesh2.addIndex(6);
    mesh2.addIndex(8);
    
    mesh2.addIndex(3);
    mesh2.addIndex(5);
    mesh2.addIndex(8);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(drawMode),20,20);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateY(ofGetFrameNum());

    switch(drawMode){
        case 0:
            mesh.drawVertices();
            break;
        case 1:
            mesh.drawWireframe();
            break;
        case 2:
            mesh.drawFaces();
            break;
        default:
            mesh.draw();
            break;
            
    }

    ofTranslate(100,100);
    ofRotateY(ofGetFrameNum());

    switch(drawMode){
        case 0:
            mesh2.drawVertices();
            break;
        case 1:
            mesh2.drawWireframe();
            break;
        case 2:
            mesh2.drawFaces();
            break;
        default:
            mesh2.draw();
            break;
            
    }



    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    drawMode++;
    if(drawMode>3){
        drawMode = 0;
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
