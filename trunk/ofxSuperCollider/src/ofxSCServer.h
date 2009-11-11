/*-----------------------------------------------------------------------------
 *
 * ofxSuperCollider: a SuperCollider control addon for openFrameworks.
 *
 * Copyright (c) 2009 Daniel Jones.
 *
 *	 <http://www.erase.net/>
 *
 * Distributed under the MIT License.
 * For more information, see ofxSuperCollider.h.
 *
 *---------------------------------------------------------------------------*/

#pragma once

#include <vector>

#include "ofxOsc.h"
#include "ofxSCResourceAllocator.h"

class ofxSCServer
{
public:	
	ofxSCServer(string hostname, unsigned int port);
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

