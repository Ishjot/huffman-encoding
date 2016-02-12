#include "Heap.h"

Heap::Heap()
{
  heap = new vector<Node*>;
  heap.push_back(NULL);
}

Heap::~Heap()
{
  for(auto it = heap.begin() + 1; it != heap.end(); ++it) // do not start at beginning because
    delete *it;                                           // first element in heap is NULL
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
      entry = new Node(characterFreq[i], letters[i]);
      heap.push_back( entry );
    }
  }

  for(int j = heap.size()/2; j >= 0; --j)
    percolateDown( j );

}

void Heap::percolateDown(int index)
{

  while(true)
  {
    int weight = heap[index]->getWeight();
    int weightLeft = heap[index*2]->getWeight();
    int weightRight = heap[index*2+1]->getWeight();
    if(weight <= weightLeft && weight <= weightRight)
      break;
    else if(weight > weightLeft && weight <= weightRight)
      //swap weight with weightLeft;
      //change index to index * 2
    else if(weight <= weightLeft && weight > weightRight)
      //swap weight with weightRight;
      //change index to index * 2 + 1
    else if(weight > weightRight && weight > weightLeft)
      //swap weight with greater of weightLeft and weightRight
      //change index to the right value, index*2 or index*2 + 1
    else
      //swap with weightRight, this means weightLeft and weightRight are equal
  }
  return;

}
