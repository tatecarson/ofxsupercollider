/*
 *  ofxSCBus.cpp
 *  openFrameworks
 *
 *  Created by Daniel Jones on 05/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSCBus.h"


int ofxSCBus::id_base = 64;


ofxSCBus::ofxSCBus(int rate, int channels, ofxSCServer *server)
{
	this->rate = rate;
	this->channels = channels;
	this->server = server;	
	
	if (this->rate == RATE_CONTROL)
	{
		this->index = server->allocatorBusControl->alloc(this->channels);
	}
	else
	{
		this->index = server->allocatorBusAudio->alloc(this->channels);
	}

//	fprintf(stderr, "got bus allocated, index %d\n", this->index);
}