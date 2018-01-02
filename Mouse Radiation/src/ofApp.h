#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofPoint randomPtForSize(ofRectangle rect, int side);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofTrueTypeFont theFont;
        ofxPanel gui;
        ofParameter<int> numOfLines;
        ofParameter<int> nodes;
        ofParameter<float> size;
//        vector<ofPolyline> lines;
        ofMesh mesh;
        vector <ofPolyline> polylines;
};
