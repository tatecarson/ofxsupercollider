/*
 *  ofxSCGroup.cpp
 *  openFrameworks
 *
 *  Created by Daniel Jones on 30/06/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSCGroup.h"

void ofxSCGroup::create(int position, int groupID)
{
	nodeID = ofxSCNode::id_base++;
	
	ofxOscMessage m;
	
	m.setAddress("/g_new");
	m.addIntArg(nodeID);
	m.addIntArg(position);
	m.addIntArg(groupID);
	
	server->osc.sendMessage(m);
	
	created = true;
}
