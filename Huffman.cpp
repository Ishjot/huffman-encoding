#include "Huffman.h"
#include <fstream>
#include <streambuf>
#include <cstdlib>

using namespace std;

Node * merge(Node * one, Node * two)
{

  Node * three = new Node( one->getWeight() + two->getWeight(),
                           '$');
  three->setRightChild( one );
  three->setLeftChild( two );

  return three;

}

Huffman::Huffman(string filename)
{
  
  characterFreq = countFreq(filename);
  encodingTree = buildEncodingTree();

}

Node * Huffman::buildEncodingTree()
{

  Heap * heap = new Heap();
  heap->buildHeap(characterFreq);
  Node * one;
  Node * two;
  Node * three;

  while(heap->getUniqueChars() > 2)
  {
    one = heap->deleteMin();
    two = heap->deleteMin();
    three = merge(one, two);
    heap->insert(three);
  }
  heap->print();

  //Node** myHeap = heap->getHeap();
  return heap->getHeap()[1];

}

string Huffman::getFileContents(string filename)
{

  //read the input file into a stream object
  ifstream myFile(filename.c_str());
  if (!myFile){
    cerr << "Could not open file " << filename << ". Exit now!" << endl;
    exit(1); 
  }
  return string((istreambuf_iterator<char>(myFile)),istreambuf_iterator<char>());

}

int* Huffman::countFreq(string filename)
{

  string getContent = getFileContents(filename);
  int* arrayOfCounts = new int[27];
  for (int i = 0; i < 27; i++){
    arrayOfCounts[i] = 0;
  }
  for (size_t i = 0; i< getContent.length(); i++){
    //int index = (int) getContent[i] - (int) ('a');
    //int index = static_cast<int>(getContent[i])-97;
    //cout << index << endl;
    int index;
    char ch = getContent[i];
    char letters [27] = {
      'a', 'b', 'c', 'd', 'e', 'f', 'g',
      'h', 'i', 'j', 'k', 'l', 'm', 'n',
      'o', 'p', 'q', 'r', 's', 't', 'u',
      'v', 'w', 'x', 'y', 'z', ' '
    };
    for(int j = 0; j < 27; j++)
      {
	if (ch == letters[j]){
	  index = j;
	  arrayOfCounts[index]++;
	}
      }
  }
  return arrayOfCounts;

}

void Huffman::print()
{
  
  cout << "Nothing to see here, yet! " << endl;

}

void Huffman::printCharacterFreq()
{

  char letters [27] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z', ' '
    }; 

  for(int i = 0; i < 27; i++)
  {
    cout << letters[i] << ":" << characterFreq[i] << " ";
  }

  cout << endl;

}
