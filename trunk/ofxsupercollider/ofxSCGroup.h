/*
 *  ofxSCGroup.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 30/06/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OFXSCGROUP_H
#define _OFXSCGROUP_H

#include <vector>
#include <tr1/unordered_map>

#include "ofxSCNode.h"
#include "ofxOsc.h"

class ofxSCGroup : public ofxSCNode
{
public:	
	ofxSCGroup() : ofxSCNode() {}
	~ofxSCGroup();

	ofxSCGroup (const ofxSCGroup & other) { copy (other); }
	ofxSCGroup& operator= (const ofxSCGroup & other) { return copy(other); }

	/// for operator= and copy constructor
	ofxSCGroup & copy(const ofxSCGroup & other);
	
	void create(int position = 0, int groupID = 1);
	void freeAll();
		
protected:
};


#endif

