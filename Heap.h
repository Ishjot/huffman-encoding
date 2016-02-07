// CS130A-Project 2
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include "Node.h"
using namespace std;


class Heap{

private:
	int occupancy;
	pair<char,int>* myHeap;

public:
	Heap();
	~Heap();
	void insert(pair<char,int> Node);
	void buildHeap(pair<char,int>* arrayOfNodes, int size);
	pair<char,int> deleteMin();
	int getUniqueChars() {return occupancy;}
	// void print();
};

#endif
