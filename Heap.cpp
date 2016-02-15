#include "Heap.h"
#include "Node.h"

Heap::Heap()
{
  heap = new vector<Node*>;
  heap->push_back(NULL);
}

Heap::~Heap()
{
  for(unsigned int i = 1; 1 < heap->size(); ++i) // do not start at beginning because
    delete heap->at(i);                           // first element in heap is NULL
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
      heap->push_back( entry );
    }
  }

  for(int j = (heap->size() - 1)/2; j > 0; --j)
    percolateDown( j );

}

void Heap::insert(Node * node)
{
  heap->push_back(node);
  for(int j = (heap->size() - 1)/2; j > 0; --j)
    percolateDown( j );
} //Insert should actually be Percolating UP, because that's how
  //to get the inserted Node to the right postition. I haven't
  //implemented the Percolate UP method yet, however, but this
  //*lazy* approach should still work

void Heap::swap( int index1, int index2 )
{

  Node * temp = (*heap)[index1];
  (*heap)[index1] = (*heap)[index2];
  (*heap)[index2] = temp;

}

void Heap::percolateDown(int index)
{

  while(true)
  {
    if(index > (heap->size() - 1)/2)
      break;
    if ((*heap)[index] == NULL || (*heap)[index*2] == NULL || (*heap)[index*2+1] == NULL)
      break;
    int weight = (*heap)[index]->getWeight();
    int weightLeft = (*heap)[index*2]->getWeight();
    int weightRight = (*heap)[index*2+1]->getWeight();
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

Node * Heap::deleteMin()
{
  Node * min = (*heap)[1];
  swap( 1, heap->size()-1 );
  heap->pop_back();
  percolateDown( 1 );  
  return min;

}
