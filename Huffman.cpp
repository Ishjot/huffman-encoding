#include "Huffman.h"
#include <fstream>
#include <streambuf>
#include <cstdlib>
#include <iostream>
#include <boost/lexical_cast.hpp>

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

  while(heap->getUniqueChars() > 1)
  {
    one = heap->deleteMin();
    two = heap->deleteMin();
    three = merge(one, two);
    heap->insert(three);
  }

  return heap->getHeap()[1];

}

void Huffman::encode(Node * root)
{

  int encoding [256] = { };
  int size = 0;
  stack<int> newStack;
  string code;
  if(root->getLeftChild() == NULL && root->getRightChild() == NULL)
  {
    newStack = myStack;
    //Read encoding from newStack in backwards order
    while( !newStack.empty() )
    {
      encoding[size] = newStack.top();
      size++;
      newStack.pop();
    }

    
    for(int i = size - 1; i >= 0; --i)
    {
    
      code += boost::lexical_cast<string>(encoding[i]);
    }
    myMap.insert( pair<char, string>(root->getValue(), code) );
    myStack.pop();
    return;
  }

  else
  {
    myStack.push(1);
    encode(root->getLeftChild());
    myStack.push(0);
    encode(root->getRightChild());
  }

  myStack.pop();
  return;

}

void Huffman::decode(string filename){
  string getContent = getFileContents(filename);
  unsigned int count = 0;
  Node* ptr = encodingTree;
  while (true){
    if (count == getContent.length()){
      break;
    }
    if (getContent[count] == '1'){
      ptr = ptr->getLeftChild();
      if (ptr->getValue() != '$'){
	cout << ptr->getValue();
	ptr = encodingTree;
      }
    }
    else{
      ptr = ptr->getRightChild();
      if (ptr->getValue() != '$'){
	cout << ptr->getValue();
	ptr = encodingTree;
      }
    }
    count++;
  }
  cout << "\n";
}

void Huffman::printEncoded( string filename )
{
  unsigned int i = 0;
  string file = getFileContents( filename );
  while(true)
  {
    if(i < file.length())
    {
      cout << myMap.at(file[i]);
      i++;
    }
    else
      break;
  }
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
