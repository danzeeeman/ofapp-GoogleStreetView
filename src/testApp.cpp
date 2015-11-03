#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //EXAMPLE URL
    //http://cbk0.google.com/cbk?output=xml&ll=51.494966,-0.146674
    //http://cbk0.google.com/cbk?output=xml&ll=%s,%s
    //
    data_url = "http://cbk0.google.com/cbk?output=xml&ll=40.434006,-79.928601";//long, lat
    
    thumbnail_url = "http://cbk0.google.com/cbk?output=thumbnail&w=640&h=320&panoid=";//width, height, panoid
    
    zoom_url = "http://cbk0.google.com/cbk?output=tile&panoid=%s&zoom=4&x=%s&y=%s";//PID, ZOOM, X, Y
    
    
    ofRegisterURLNotification(this);
    ofLoadURLAsync(data_url);
    loading = true;
    
    
    fbo.allocate(512*12, 512*6, GL_RGB);
    fbo.begin();
    ofClear(0, 0, 0);
    fbo.end();
    sphere.set(1000, 60);
    sphere.setPosition(ofVec3f(0, 0, 0));
    
    sphere.mapTexCoordsFromTexture(fbo.getTextureReference());
    cam.setPosition(0, 0, 0);
    
}

//<panorama>
//<data_properties image_width="13312" image_height="6656" tile_width="512" tile_height="512" image_date="2008-03" pano_id="sLaiF6Jex7mJmNol7tdOoA" num_zoom_levels="3" lat="51.495078" lng="-0.147004" original_lat="51.495073" original_lng="-0.146987" best_view_direction_deg="113.528">
//<copyright>© 2012 Google</copyright>
//<text>Eccleston Place</text>
//<region>London, England</region>
//<country>United Kingdom</country>
//<data_flag>1</data_flag>
//</data_properties>
//<projection_properties projection_type="spherical" pano_yaw_deg="204.15" tilt_yaw_deg="-17.52" tilt_pitch_deg="0.75"/>
//<annotation_properties>
//<link yaw_deg="25.37" pano_id="t_mnKSugTLrQTEnJplXQ3A" road_argb="0x80ffffff" scene="0">
//<link_text>Ebury Street / Eccleston Place</link_text>
//</link>
//<link yaw_deg="205.51" pano_id="x8-xIY7hWYkqrVqoePGdJQ" road_argb="0x80ffffff" scene="0">
//<link_text>Eccleston Place</link_text>
//</link>
//</annotation_properties>
//</panorama>



//--------------------------------------------------------------
void testApp::urlResponse(ofHttpResponse & response){
    if(response.status==200 && response.request.url == data_url){
        XML.loadFromBuffer(response.data);
        data_prop_pano_id = XML.getAttribute("panorama:data_properties", "pano_id", "BLANK");
        if(data_prop_pano_id != "BLANK"){
            thumbnail_url+=data_prop_pano_id;
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 12; j++){
                    ofLoadURLAsync("http://cbk0.google.com/cbk?output=tile&panoid="+ofToString(data_prop_pano_id)+"&zoom=4&x="+ofToString(j)+"&y="+ofToString(i));
                }
            }
        }
    }if(response.status==200 && response.request.url != data_url){
        img.loadImage(response.data);
        
        //you don't have to resize it
//        img.resize(300, 300);
        images.push_back(img);
        
        loading = false;
    }
    
}


//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    if(!loading){
        if(images.size() >= 3*6){
            int x = 0;
            int y = 0;
            fbo.begin();
            ofClear(0, 0, 0);
            ofSetColor(255, 255, 255);
            for(int i= 0; i < images.size(); i++){
                images[i].draw(x*images[i].width, y*images[i].width);
                if(x < 11){
                    x++;
                }else{
                    x=0;
                    y++;
                }
                
            }
            fbo.end();
        }else{
            img.draw(0, 0);
        }
        ofSetColor(255, 255, 255);
        cam.begin();
                ofEnableDepthTest();
        fbo.getTextureReference().bind();
        sphere.draw();
        fbo.getTextureReference().unbind();
                ofDisableDepthTest();
        cam.end();
        
//        fbo.draw(0, 0);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}