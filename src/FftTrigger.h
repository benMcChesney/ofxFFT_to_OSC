//
//  FftTrigger.h
//  emptyExample
//
//  Created by Ben McChesney on 10/30/12.
//
//
#include "ofMain.h"

#ifndef emptyExample_FftTrigger_h
#define emptyExample_FftTrigger_h

class FftTrigger
{
    public :
        FftTrigger( ) { } 
        ~FftTrigger ( ) { }
    
        void setup ( float lowBand , float highBand ) ;
        void draw( ) ;
        bool hitTest( float x , float y ) ;
    
        ofRectangle bounds ;
        float value ;
        ofColor color ;
    
        int lowBand;
        int highBand;
        float height;
        string name;
	
        bool hit;
        bool sent;

        void updateBands() ; 
        void updateBands( float lowBand, float highBand ) ;
    
        float lastTriggerTime ;
        float minTriggerDelay ;
        bool trigger() ;
    
    
};

#endif
