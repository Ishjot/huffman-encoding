// CS130A-Project 2
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Heap{

private:
	vector<Node *> heap;

public:
  //Constructor and Destructor
	Heap();
	~Heap();
  //Modifiers
  void buildHeap();
	void insert(Node * node);

  void percolateDown(int index);
	Node* deleteMin();

	int getUniqueChars() { return this->size; }
	// void print();
};

#endif
