#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxFft.h"
#include "ofxOsc.h"
#include "FftTrigger.h"
#include "ofxUI.h"

#define MIC 0
#define NOISE 1
#define SINE 2

#define HOST "localhost"
#define PORT 1200

enum Trigger_Mode_t {TM_NONE=0, TM_SETTING, TM_MOVING, TM_NAMING};


class testApp : public ofBaseApp{
	
public:
	
	~testApp();
	
	void setup();
	void update();
	void draw();
	
	void loadSettings();
	void saveSettings();
	
	void drawTriggers();
	
	void checkTriggers();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	// ofxFft related
	void plot(float* array, int length, float yScale, int xScale, float yOffset);
	void audioReceived(float* input, int bufferSize, int nChannels);
	
	
	int bufferSize;
	ofxFft* fft;
	float* audioInput;
	float* fftOutput;
	float* eqFunction;
	float* eqOutput;
	float* ifftOutput;
	
	// ofxFft related app values
	int mode;
	bool useEQ;
	
	// OSC related
	ofxOscSender sender;
	void handleOSC();
	void sendSpectrum();
	void sendTriggers();
	bool sendFullSpectrum;
	
	
	vector <FftTrigger> triggers;
	
	//trigger stuff for drawing.
	ofPoint oldMouse;
	bool settingTrigger;
	Trigger_Mode_t triggerMode;
	
	int selTrigger;
    
    
    //ofxUI
    ofxUICanvas *gui;
	void guiEvent(ofxUIEventArgs &e);
    
    void setupOfxUI( ) ;
    
    bool bClearXml ;
    bool bGuiEnabled ;
    
    float amplitudeScale ;
    float triggerDelay ;
    
    void createNewTrigger ( float x , float y ) ; 
};

#endif
