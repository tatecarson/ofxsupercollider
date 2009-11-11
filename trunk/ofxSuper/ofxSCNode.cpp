/*
 *  ofxSCNode.cpp
 *  openFrameworks
 *
 *  Created by Daniel Jones on 29/06/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSCNode.h"
#include "ofxSCGroup.h"

int ofxSCNode::id_base = 2000;

ofxSCNode::ofxSCNode()
{
	nodeID = 0;
	created = false;
	server = ofxSCServer::local();
}

ofxSCNode::~ofxSCNode()
{
}

void ofxSCNode::addToHead(ofxSCGroup group)
{
	this->create(0, group.nodeID);
}

void ofxSCNode::addToTail(ofxSCGroup group)
{
	this->create(1, group.nodeID);
}

void ofxSCNode::free()
{
	ofxOscMessage m;
	m.setAddress("/n_free");
	m.addIntArg(nodeID);
	server->osc.sendMessage(m);
	
	created = false;
}

void ofxSCNode::create(int position, int groupID)
{
}