/*
 *  ofxSCNode.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 29/06/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OFXSCNODE_H
#define _OFXSCNODE_H

#include <vector>
#include "ofxOsc.h"
#include "ofxSCServer.h"
//#include "ofxSCGroup.h"

class ofxSCGroup;



class ofxSCNode
{
public:	
	ofxSCNode();
	~ofxSCNode();
	
	void addToHead(ofxSCGroup group);
	void addToHead(unsigned int groupID) { create(0, groupID); }
	void addToHead() { create(0, 1); }
	void addToTail(ofxSCGroup group);
	void addToTail(unsigned int groupID) { create(1, groupID); }
	void addToTail() { create(1, 1); }
	void addBefore(const ofxSCNode& node) { create(2, node.nodeID); }
	void addAfter(const ofxSCNode& node) { create(3, node.nodeID); }
	
	// pure virtual method
	virtual void create(int position = 0, int groupID = 1);
	
	void free();

	static int id_base;
	
	// can't use 'id' as a keyword when mixing with objective-c!
	int nodeID;
		
protected:

	bool created;
	
	ofxSCServer *server;

};

#endif

