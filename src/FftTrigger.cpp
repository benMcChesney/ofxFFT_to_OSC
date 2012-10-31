//
//  FftTrigger.cpp
//  emptyExample
//
//  Created by Ben McChesney on 10/30/12.
//
//

#include "FftTrigger.h"

void FftTrigger::setup ( float _lowBand , float _highBand )
{
    
    updateBands( _lowBand, _highBand ) ; 
    color = ofColor( ofRandom ( 255 ) , ofRandom( 255 ) , ofRandom( 255 ) ) ;
    
    lastTriggerTime = ofGetElapsedTimef() ;
    minTriggerDelay = 0.1f ;
   
}

void FftTrigger::draw( )
{
    ofPushStyle() ;
        ofNoFill( ) ;
    /*
        if ( hit == true )
            ofSetColor( 255 , 0 , 0 ) ; //255 - color.r , 255 - color.g , 255 - color.b ) ;
        else
            ofSetColor( 0 , 255 , 0 ) ; //color ) ;
    */
        updateBands( ) ; 
        ofRect( bounds ) ;
    ofPopStyle() ;
}

bool FftTrigger::trigger( )
{
    if ( ofGetElapsedTimef() > ( lastTriggerTime + minTriggerDelay ))
    {
        minTriggerDelay = 0.1f ;
        lastTriggerTime = ofGetElapsedTimef() ;
        return true ;
    }
    else
    {
        return false ;
    }
}

bool FftTrigger::hitTest( float x , float y )
{
    if ( (x > bounds.x && x < ( bounds.x + bounds.width )) && ( y > bounds.y && y < ( bounds.y + bounds.height )) ) 
        return true ;
    else
        return false ;
}

void FftTrigger::updateBands( )
{
    bounds = ofRectangle( lowBand*4 ,
                         ofGetHeight() - 16 - height * 512 - 15 ,
                         ( highBand*4 ) - ( lowBand*4 )  ,
                         15) ;
}

void FftTrigger::updateBands( float _lowBand, float _highBand )
{
    lowBand = _lowBand ;
    highBand = _highBand ;
    updateBands() ; 
}
