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

#include "ofxSCServer.h"

ofxSCServer *ofxSCServer::plocal = NULL;

/*
ofxSCServer::ofxSCServer()
{
	fprintf(stderr, "OSC setup\n");
	osc.setup("localhost", 57110);
//	osc.setup("192.168.1.100", 57110);
}
 */

ofxSCServer::ofxSCServer(string hostname = "localhost", unsigned int port = 57110)
{
	this->hostname = hostname;
	this->port = port;

	osc.setup(hostname, port);
	
	allocatorBusAudio = new ofxSCResourceAllocator(512);
	allocatorBusAudio->pos = 64;
	
	allocatorBusControl = new ofxSCResourceAllocator(512);
	allocatorBuffer = new ofxSCResourceAllocator(512);
	
	if (plocal == 0)
		plocal = this;
}

ofxSCServer::~ofxSCServer()
{
}

ofxSCServer *ofxSCServer::local()
{
	if (plocal == 0)
	{
		plocal = new ofxSCServer;
	}
	
	return plocal;
}

void ofxSCServer::notify()
{
	ofxOscMessage m;
	m.setAddress("/notify");
	m.addIntArg(1);
	osc.sendMessage(m);
}
