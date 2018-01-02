#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(radius.setup("radius", 20, 0, 300));
    gui.add(resolution.setup("resolution", 20, 0, 300));
    gui.add(normalLength.setup("normalLength", 20, 0, 100));
    gui.add(rate.setup("rate", 0.001, 0, 0.2));
    gui.add(tornadoFactor.set("tornadoFactor", 0.01, 0, 100));

}

//--------------------------------------------------------------
void ofApp::update(){
    count = count + rate;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
//    ofDrawCircle(ofGetWidth()/4, ofGetHeight()/4, count);
    ofSetDepthTest(true);
    camera.begin();
    
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_LINES);
//    drawPoint = ofVec3f(ofGetWidth()/2, ofGetHeight()/2,0);
    drawPoint = ofVec3f(0,0,0);
    float angle = TWO_PI / resolution;
    
    for(int i = 0; i <= resolution; i++){
        float drawAngle = i * angle;
        cout << drawAngle << endl;
        
        circleX = drawPoint.x + radius * cos(drawAngle + count);
        circleY = drawPoint.y + radius * sin(drawAngle + count);
        circleZ = drawPoint.z + ofRandom(tornadoFactor) * 10;
        
        ofVec3f tempPoint = ofVec3f(circleX,circleY,circleZ);
        mesh.addColor(ofColor(0,0,0));
        mesh.addVertex(tempPoint);
        
        float normalX = circleX + normalLength * cos(drawAngle - count);
        float normalY = circleY + normalLength * sin(drawAngle - count);
        float normalZ = circleZ;
        ofVec3f normalPoint = ofVec3f(normalX,normalY,normalZ);
        mesh.addColor(ofColor(255,0,255));
        mesh.addVertex(normalPoint);
    }
    
    mesh.draw();


   
    camera.end();
    ofSetDepthTest(false);
    gui.draw();
    ofDrawBitmapString(ofGetFrameRate(), ofGetWidth() - 70, ofGetHeight() - 30);
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
