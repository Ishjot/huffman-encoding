// CS130A-Project 2
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include "Node.h"
using namespace std;

class Heap{

private:
  Node** heap;
  int occupancy;

public:
  //Constructor and Destructor
  Heap();
  ~Heap();

  //Getters
  Node ** getHeap() { return this->heap; }

  //Modifiers
  void buildHeap( int * characterFreq );
  void insert(Node * node);
  void swap(int index1, int index2);

  void percolateDown(int index);
  void percolateUp(int index);
  Node* deleteMin();

  int getUniqueChars() { return occupancy; }
  void print();
};

#endif
