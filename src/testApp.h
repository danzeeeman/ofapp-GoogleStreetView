#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxOpenCv.h"
class testApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void urlResponse(ofHttpResponse & response);
    
    ofxXmlSettings XML, nycXML;
    string data_url, thumbnail_url, zoom_url, NYCdata;
    
    string data_prop_pano_id;
    vector<ofImage> images;
    ofImage img;
    ofImage sum;
    
    bool loading;
    ofEasyCam cam;
    ofFbo fbo;
    
    ofSpherePrimitive sphere;
};
