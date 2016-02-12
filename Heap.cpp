#include "Heap.h"

Heap::Heap()
{
  myHeap = new Node * [HEAP_SIZE];
  for(int i = 0; i < HEAP_SIZE; i++)
    myHeap[i] = NULL;
}

Heap::~Heap()
{
  for(int i = 0; i < HEAP_SIZE; i++)
    delete myHeap[i];

  delete [] myHeap;
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
  int currIndex = 0;

  for(int i = 0; i < 27; i++)
  {
    if(characterFreq[i] != 0)
    {
      entry = new Node(characterFreq[i], letters[i]);
      myHeap[currIndex] = entry;
      currIndex++;
    }
  }

  for(int j = 

}
