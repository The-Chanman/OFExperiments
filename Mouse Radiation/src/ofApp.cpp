#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(255,255,255);
    gui.setup();
    gui.add(numOfLines.set("Num of Lines", 10000, 0, 50000));
    gui.add(nodes.set("nodes", 20, 0, 50));
    gui.add(size.set("size", 100, 0, 600));
    mesh.setMode(OF_PRIMITIVE_LINES);
    theFont.load("Raleway.ttf", 300, true, true, true);
//    ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
ofPoint ofApp::randomPtForSize(ofRectangle rect, int side){
    
    ofPoint aa = ofPoint(rect.x, rect.y);
    ofPoint bb = ofPoint(rect.x + rect.width, rect.y);
    ofPoint cc = ofPoint(rect.x + rect.width, rect.y + rect.height);
    ofPoint dd = ofPoint(rect.x, rect.y + rect.height);
    
    if (side == 0){
        return aa + ofRandom(0,1) * (bb-aa);
    } else if (side == 1){
        return bb + ofRandom(0,1) * (cc-bb);
    } else if (side == 2){
        return cc + ofRandom(0,1) * (dd-cc);
    } else {
        return dd + ofRandom(0,1) * (aa-dd);
    }
    return ofPoint(0,0);
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    ofSetColor(0, 0, 0);
    vector < ofTTFCharacter > paths = theFont.getStringAsPoints("hello");
    
//    ofTranslate(ofGetWidth()/20, ofGetHeight()/2);
    for (int i = 0; i < paths.size(); i++){
        
        // for every character break it out to polylines
        vector <ofPolyline> tempPolylines = paths[i].getOutline();
        for (int j = 0; j < tempPolylines.size(); j++){
            for (int k = 0; k < tempPolylines[j].size(); k++){
                tempPolylines[j][k].y += ofGetHeight()/2;
            }
            polylines.push_back(tempPolylines[j]);
            
        }
    }
    
    for (int i = 0; i < polylines.size(); i++) {
        for (int j = 0; j < polylines[i].size(); j++) {
            ofSetColor(100, 100, 100);

            ofDrawCircle(polylines[i][j], 3);
        }
        ofSetColor(0);

        polylines[i].draw();
    }
//    ofSetColor(255, 255, 255);
    
    
//    ofPolyline temp;
//    for (int i = 0; i < nodes; i++){
//        float x = ofGetWidth()/2  + cos(i/float(nodes) * TWO_PI) * size;
//        float y = ofGetHeight()/2 + sin(i/float(nodes) * TWO_PI) * size;
//        temp.addVertex(ofPoint(x,y));
//    }

    ofRectangle rect(0,0,ofGetWidth(), ofGetHeight());
//    bool drawn = false;
//    while (!drawn) {
    for (int count = 0; count < 100; count ++) {
        int side = ofRandom(0,4);
        int sideb = ofRandom(0,4);
        if (side != sideb){
            ofPoint a = randomPtForSize(rect, side);
            ofPoint b = ofPoint(ofGetMouseX(), ofGetMouseY());
            bool intersects = false;
            ofPoint inter;

            for(int i = 0; i < polylines.size(); i++){
                for(int j = 0; j < polylines[i].size(); j++){
                    int nextpoint = (j == polylines[i].size() - 1 )? 0: j+1 ;
                    ofPoint c = polylines[i][nextpoint];
                    ofPoint d = polylines[i][j];
                    
                    if(ofLineSegmentIntersection(a, b, c, d, inter)){
                        intersects = true;
                        break;
                    };
                }
                if (intersects){
                    break;
                }
            }
            if(!intersects){
                ofDrawLine(a,b);
            } else  {
                ofDrawLine(b,inter);
            }
        }
    }
    
//            cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
//            mesh.clear();
//            mesh.addColor(ofColor(0,0,0,255));
//            mesh.addVertex(a);
//            mesh.addColor(ofColor(0,0,0,255));
//            mesh.addVertex(b);
//            mesh.draw();
//            drawn = true;
//            if (!bIntersects(a,b, polylines[0])){
//                cout << "Doesn't intersect" << endl;
//            }
//        }
//    }
    
//    if (mesh.getNumVertices() < numOfLines) {
//        for (int i = 0; i < 200; i++){
//            int side = ofRandom(0,4);
//            int sideb = ofRandom(0,4);
//            if (side != sideb){
//                ofPoint a =randomPtForSize(rect, side);
//                ofPoint b =randomPtForSize(rect, sideb);
//                if (!bIntersects(a,b, polylines[0])){
//                    mesh.addColor(ofColor(0,0,0,15));
//                    mesh.addVertex(a);
//                    mesh.addColor(ofColor(0,0,0,15));
//                    mesh.addVertex(b);
//                }
//            }
//        }
//        ofBackground(255,255,255);
//        mesh.draw();
//        cout << mesh.getNumVertices() << endl;
//    } else if (mesh.getNumVertices() > numOfLines){
//        for(int i = mesh.getNumVertices(); i > numOfLines; i-=2){
//            mesh.removeVertex(0);
//            mesh.removeVertex(0);
//        }
//        ofBackground(255,255,255);
//        mesh.draw();
//        cout << mesh.getNumVertices() << endl;
//    }
    gui.draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
