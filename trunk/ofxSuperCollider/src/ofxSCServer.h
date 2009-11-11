/*
 *  ofxSCServer.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 29/06/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OFXSCSERVER_H
#define _OFXSCSERVER_H

#include <vector>

#include "ofxOsc.h"
#include "ofxSCResourceAllocator.h"

class ofxSCServer
{
public:	
	ofxSCServer(string hostname, unsigned int port);
//	ofxSCServer();
	~ofxSCServer();

	ofxOscSender osc;
	
	static ofxSCServer *local();
	
	void notify();
	
	ofxSCResourceAllocator *allocatorBusAudio;
	ofxSCResourceAllocator *allocatorBusControl;
	ofxSCResourceAllocator *allocatorBuffer;
	ofxSCResourceAllocator *allocatorSynth;
	
protected:

	static ofxSCServer *plocal;
	string hostname;
	unsigned int port;
};

#endif

