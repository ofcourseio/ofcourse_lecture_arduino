#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
	ofBackground(255);
    
	ard.connect("/dev/tty.usbmodemfd121", 57600);
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

}
//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
	ard.sendDigitalPinMode(02, ARD_INPUT);
	bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
	// update the arduino, get any data or messages.
	ard.update();
    
    
    cout << ard.getDigital(2) << endl;
    
    
    
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
    
	ard.sendDigital(13, ARD_HIGH);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
	ard.sendDigital(13, ARD_LOW);
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
