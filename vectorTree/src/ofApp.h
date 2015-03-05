#pragma once

#include "ofMain.h"
#include "CLine.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector<CLine*> lines;
private:
    void generateFan(ofPoint    _p,
                     float      _angle,
                     int        _children,
                     int        _generations,
                     float      _radius,
                     float      _spread);
    
    
		
};