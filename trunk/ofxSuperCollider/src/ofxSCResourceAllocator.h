/*
 *  ofxSCResourceAllocator.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 05/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>

class ofxSCResource
{

public:
	
	ofxSCResource(int address, int size)
	{
		this->address = address;
		this->size = size;
		this->next = NULL;
	}
	
	int address;
	int size;
	
	// pointer to next resource in free list
	ofxSCResource *next;
	
};

class ofxSCResourceAllocator
{
public:
	ofxSCResourceAllocator(int capacity);
	
	int alloc (int resource_size);
	void free (int address);
	
	int capacity;
	int pos;
	std::vector <ofxSCResource *> resources;
	std::vector <ofxSCResource *> free_lists;
};