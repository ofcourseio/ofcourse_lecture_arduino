#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
	ard.connect("/dev/tty.usbmodemfd121", 57600);
	ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    
	bSetupArduino	= false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mouseModulate = (int)(128 + 128 * sin(ofGetElapsedTimef()));
	cout << mouseModulate <<endl;
	updateArduino();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(mouseModulate);
}


//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
	
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
	ard.sendDigitalPinMode(6, ARD_PWM);
	bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    mouseModulate = ofMap(mouseX, 0, ofGetWidth(), 0,255);
    //modulating with mouse instead of time
	ard.update();
	
	if (bSetupArduino) {
		ard.sendPwm(6, mouseModulate);
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
