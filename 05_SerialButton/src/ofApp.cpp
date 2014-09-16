#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	ofSetVerticalSync(true);
	ofBackground(255,255,255);
	ofSetLogLevel(OF_LOG_NOTICE);
    
	//-----------------------------------
    
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	//----------------------------------- note:
	
    
	serial.setup(5, 57600); //open the first device
    
	posX = 100;
	posY = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    
	if (serial.available()){
        
		while( (serial.readBytes( bytesReturned, 1)) > 0){
            
			if ( bytesReturned[0] == 1) {
				cout << "one"  << endl;
				serial.writeByte('a');
                posX+= 3;
			}
            
		}
		
	}
    
	if(posX >= ofGetWidth()+30) posX = -30;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofFill();
	ofSetColor(255, 0, 0);
	ofCircle(posX, posY, 30);

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
    
	bSendSerialMessage = true;

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
