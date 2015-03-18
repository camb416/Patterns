#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    mesh3.clear();
    
    drawMode = 0;
   
    int numRings = ofRandom(20)+5;
    int ringRes;
    int ringRadius;
    int curIndex = 0;
    float offset;
    float zee = 0;
    
    for(int i=0;i<numRings;i++){
        //ringRes = ofRandom(20)+3;
        ringRes = ofRandom(10)+3;
        ringRadius = ofRandom(50)+10;
        offset = ofRandom(PI/4);
        zee += ofRandom(20)+10;
        for(int j=0;j<ringRes;j++){
            float a = TWO_PI/ringRes*(float)j+offset;
            
            ofPoint p = ofPoint(sin(a)*ringRadius,zee,cos(a)*ringRadius);
            mesh3.addVertex(p);
            mesh3.addColor(ofFloatColor(1.0,1.0,1.0));
            
            if(i>0){
                if(j<(ringRes+offset)-1){
                mesh3.addIndex(curIndex);
                mesh3.addIndex(curIndex-3);
                mesh3.addIndex(curIndex-2);
                } else {
                    mesh3.addIndex(curIndex);
                    mesh3.addIndex(curIndex-3);
                    mesh3.addIndex(curIndex-5);
                }
                if(j>0){
                    mesh3.addIndex(curIndex);
                    mesh3.addIndex(curIndex-1);
                    mesh3.addIndex(curIndex-3);
                }
            }
            curIndex++;
            
                               
        }
      
    }

    
    
    
/*
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
 */
    /*

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
    
    */
    
    
    
    
    /*
    
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
    */
    
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .75) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 170.f/255.f, 185.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(84.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(180.f/255.f,150.f/255.f,135.f/255.f) );
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    ofSetSphereResolution(24);
    
    pointLight.setPosition(318.04837,384,500);
    pointLight2.setPosition(751.597167,373.140991,-300);
    pointLight3.setPosition(454.354034,236.022079,635.213867);
    
}

//--------------------------------------------------------------
void ofApp::update(){
   /* pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.15)*(ofGetWidth()*.3),
                            ofGetHeight()*.5 + sin(ofGetElapsedTimef()*.7)*(ofGetHeight()), -300);
    
   pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
                            );
    */
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    
    ofDrawBitmapString(ofToString(drawMode),20,20);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2-100);
    ofRotateY(ofGetFrameNum());
/*
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
 */
    ofEnableLighting();
    pointLight.enable();
   // pointLight2.enable();
   // pointLight3.enable();
    material.begin();
     mesh3.drawFaces();
       material.end();
    ofDisableLighting();
    //mesh3.drawWireframe();
    mesh3.drawVertices();
    switch(drawMode){
        case 0:
            
            break;
        case 1:
            mesh3.drawWireframe();
            break;
        case 2:
           
            break;
        default:
            mesh3.draw();
            break;
            
    }



    ofPopMatrix();
 //   if(bDrawLights) {
     /*   ofFill();
       ofSetColor(pointLight.getDiffuseColor());
        pointLight.draw();
        ofSetColor(pointLight2.getDiffuseColor());
        pointLight2.draw();
        ofSetColor(pointLight3.getDiffuseColor());
        pointLight3.draw();
  */
      //  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
            case 's':
            case 'S':
            setup();
            break;
        default:
            drawMode++;
            if(drawMode>3){
                drawMode = 0;
            }
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
    ofLog() << endl;
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
