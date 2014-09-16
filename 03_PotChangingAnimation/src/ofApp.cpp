#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0,0,0);
    ofSetCircleResolution(60);
	ard.connect("/dev/tty.usbmodem1411", 57600);
	//ard.connect("/dev/ttyUSB0", 57600);
	ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    
	bSetupArduino	= false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
	updateArduino();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor(255);
    ofCircle(ard.getAnalog(0), 100, 30);

}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
	
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
	ard.sendAnalogPinReporting(0, ARD_ANALOG);
	bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
	ard.update();
    
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
