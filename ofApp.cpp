#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
	ofNoFill();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	int radius = 8;
	for (int x = span * 1.5; x <= ofGetWindowWidth() - span * 1.5; x += span) {

		for (int y = span * 1.5; y <= ofGetWindowHeight() - span * 1.5; y += span) {

			bool flag = ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.003) < 0.5 ? true : false;

			if (flag) {

				ofDrawLine(x - span * 0.5, y, x + span * 0.5, y);

				bool left_flag = ofNoise((x - span) * 0.01, y * 0.01, ofGetFrameNum() * 0.003) < 0.5 ? true : false;
				if (left_flag == false || x == span * 1.5) {

					ofBeginShape();
					for (int deg = 90; deg <= 270; deg += 90) {

						ofVertex(x - span * 0.4 + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));
					}
					ofEndShape();
				}

				bool right_flag = ofNoise((x + span) * 0.01, y * 0.01, ofGetFrameNum() * 0.003) < 0.5 ? true : false;
				if (right_flag == false || x == ofGetWindowWidth() - span * 1.5) {

					ofBeginShape();
					for (int deg = 270; deg <= 450; deg += 90) {

						ofVertex(x + span * 0.4 + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));
					}
					ofEndShape();
				}

			}
			else {

				ofDrawLine(x, y - span * 0.5, x, y + span * 0.5);

				bool top_flag = ofNoise(x * 0.01, (y - span) * 0.01, ofGetFrameNum() * 0.003) < 0.5 ? true : false;
				if (top_flag || y == span * 1.5) {

					ofBeginShape();
					for (int deg = 180; deg <= 360; deg += 90) {

						ofVertex(x + radius * cos(deg * DEG_TO_RAD), (y - span * 0.4) + radius * sin(deg * DEG_TO_RAD));
					}
					ofEndShape();
				}

				bool bottom_flag = ofNoise(x * 0.01, (y + span) * 0.01, ofGetFrameNum() * 0.003) < 0.5 ? true : false;
				if (bottom_flag || y == ofGetWindowHeight() - span * 1.5) {

					ofBeginShape();
					for (int deg = 0; deg <= 180; deg += 90) {

						ofVertex(x + radius * cos(deg * DEG_TO_RAD), (y + span * 0.4) + radius * sin(deg * DEG_TO_RAD));
					}
					ofEndShape();
				}

			}

		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}