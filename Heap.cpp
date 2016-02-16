#include "Heap.h"
#include "Node.h"

#include <iostream>
#include <sstream>

Heap::Heap()
{
  heap = new Node*[27];
  for (int i = 0; i < 27; ++i){
    heap[i] = NULL;
  }
  occupancy = 0;
}

Heap::~Heap()
{
  /*
  for(int i = 1; i<occupancy; ++i) // do not start at beginning because
    delete heap[i];                            // first element in heap is NULL
  */
  delete [] this->heap;
}

void Heap::buildHeap(int * characterFreq)
{

  char letters [27] = {
    'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', ' '
    };

  Node * entry;

  for(int i = 0; i < 27; i++)
  {
    if(characterFreq[i] != 0)
    {
      occupancy++;
      entry = new Node(characterFreq[i], letters[i]);
      heap[occupancy] = entry;
    }
  }

  for(int j = occupancy/2-1; j > 0; --j){
    percolateDown( j );
  }

}

void Heap::insert(Node * node)
{
  if (occupancy >= 27){
    cout<< "Error: Not Enough Space!\n";
    return;
  }
  occupancy++;
  heap[occupancy] = node;
  percolateUp( occupancy );

} //Insert should actually be Percolating UP, because that's how
  //to get the inserted Node to the right postition. I haven't
  //implemented the Percolate UP method yet, however, but this
  //*lazy* approach should still work

void Heap::swap( int index1, int index2 )
{

  Node * temp = heap[index1];
  heap[index1] = heap[index2];
  heap[index2] = temp;

}

void Heap::percolateDown(int index)
{

  while(true)
  {
    if(index > (occupancy/2))
      break;
    if (heap[index] == NULL || heap[index*2] == NULL)
      break;
    int weight =  heap[index]->getWeight();
    int weightLeft = heap[index*2]->getWeight();
    if (heap[index*2+1] == NULL){
      if (weight>weightLeft){
	swap(index, index*2);
      }
      break;
    }
    int weightRight = heap[index*2+1]->getWeight();
    if(weight <= weightLeft && weight <= weightRight)
      break;
    else if(weight > weightLeft && weight <= weightRight)
    {
      swap( index, index*2 );
      index = index * 2;
    }
    else if(weight <= weightLeft && weight > weightRight)
    {
      swap( index, index*2 + 1);
      index = index*2 + 1;
    }
    else // if (weight > weightRight && weight > weightLeft)
    {
      if(weightLeft < weightRight)
      {
        swap( index, index*2 );
        index = index*2;
      }
      else
      {
        swap( index, index*2 + 1 );
        index = index*2 + 1;
      }
    }
  }
  return;
}

void Heap::percolateUp(int index){
  while(true){
    if (index == 1){
      break;
    }
    else if (heap[index]->getWeight() < heap[index/2]->getWeight()){
	swap(index, index/2);
	index = index/2;
    }
    else {
      break;
    }
  }
}

Node * Heap::deleteMin()
{
  Node * min = heap[1];
  swap( 1, occupancy );
  heap[occupancy] = NULL;
  occupancy--;
  percolateDown( 1 );  
  return min;

}

void Heap::print(){
  for (int i = 1; i<=occupancy; i++)
    {
      heap[i]->print();
    }
  cout << "\n";
}
