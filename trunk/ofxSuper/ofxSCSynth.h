/*
 
 Copyright 2009 Daniel Jones <dan@erase.net>
 Distributed under the terms of the GNU Lesser General Public License v3
 
 This file is part of the ofxSuperCollider openFrameworks OSC addon.
 
 ofxSuperCollider is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 ofxSuperCollider is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with ofxSuperCollider.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _OFXSCSYNTH_H
#define _OFXSCSYNTH_H

#include <vector>
#include <tr1/unordered_map>

#include "ofxSCNode.h"
#include "ofxOsc.h"

typedef std::tr1::unordered_map<string, float> dictionary;

class ofxSCSynth : public ofxSCNode
{
public:	
	ofxSCSynth(char * name = "sine", ofxSCServer *server = ofxSCServer::local());
	~ofxSCSynth();

	ofxSCSynth (const ofxSCSynth & other) { copy (other); }
	ofxSCSynth& operator= (const ofxSCSynth & other) { return copy(other); }

	/// for operator= and copy constructor
	ofxSCSynth & copy(const ofxSCSynth & other);
	
	void create(int position = 0, int groupID = 1);
	void grain(int position = 0, int groupID = 1);
	
	void set(string arg, float value);
	void set(string arg, int value);
		
protected:

	string name;
	dictionary args;
};


#endif

