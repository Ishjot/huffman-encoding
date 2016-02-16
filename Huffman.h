#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include <stack>
#include <map>
#include "Node.h"
#include "Heap.h"


using namespace std;

class Huffman {
private:
	Node * encodingTree;
	int * characterFreq;
	stack<int> myStack; //for encoding
	map<char,string> myMap;

public:
	Huffman(string filename);
	~Huffman();
	Node* buildEncodingTree();
	void decode(string filename);
	void encode(Node* root);
	void encode() { encode(this->encodingTree); }
	void printEncoded( string filename );

	string getFileContents (string filename);
	int* countFreq(string filename);

	void print();
	void printCharacterFreq();

};

#endif
