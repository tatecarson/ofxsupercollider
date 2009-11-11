/*
 *  ofxSCBus.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 05/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OFXSCBUS_H
#define _OFXSCBUS_H

#include "ofxSuperCollider.h"

class ofxSCBus
{
	
public:
	ofxSCBus(int rate = RATE_AUDIO, int channels = 2, ofxSCServer *server = ofxSCServer::local());
	
	static int id_base;
	
	ofxSCServer *server;
	int rate;
	int index;
	int channels;
	
};

#endif