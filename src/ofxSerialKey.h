//
//  ofxSerialKey.h
//
//  Created by enrico<naus3a>viola on 11/14/18
//  naus3a.ml
//  naus3a@gmail.com
//

#pragma once
#include "ofMain.h"
#include "ofxMD5.h"

class ofxSerialKey{
public:
    ofxSerialKey(){
        bActivated = false;
        secret = "";
    }
    
    void feedKey(string _s){
        bActivated = isGoodKey(_s);
    }
    
    string generateKey(string _s){return md5.calcHash(_s);}
    void setSecret(string _s){secret=generateKey(_s);}
    bool isGoodKey(string _s){return (_s==secret);}
    bool isActivated(){return bActivated;}
protected:
    ofxMD5 md5;
    string secret;
    bool bActivated;
};
