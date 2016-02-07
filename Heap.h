// CS130A-Project 2
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include "freqCounter.h"
using namespace std;

class Heap{

private:
	int occupancy;
	pair<char,int>* myHeap;

public:
	Heap();
	~Heap();
	//void buildArray(sting filename);
	void minHeapify(pair<char,int>* arrayOfNodes, int size);
	pair<char,int> deleteMin();
	// void print();
};

#endif
