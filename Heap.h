// CS130A-Project 2
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Heap{

private:
	vector<Node *> * heap;

public:
  //Constructor and Destructor
	Heap();
	~Heap();

  //Getters
  vector<Node *> * getHeap() { return this->heap; }

  //Modifiers
  void buildHeap( int * characterFreq );
	void insert(Node * node);
  void swap(int index1, int index2);

  void percolateDown(int index);
	Node* deleteMin();

	int getUniqueChars() { return this->heap->size() - 1; }
	// void print();
};

#endif
