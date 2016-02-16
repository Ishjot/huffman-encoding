#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include <stack>
#include <unordered_map>
#include "Node.h"
#include "Heap.h"


using namespace std;

class Huffman {
private:
	Node * encodingTree;
	int * characterFreq;
	stack<int> myStack; //for encoding
	unordered_map<char,string> map;

public:
	Huffman(string filename);
	~Huffman();
	Node* buildEncodingTree();
	void decode(string filename);
	void encode(Node* root);
	void encode() { encode(this->encodingTree); }
	void printEncoded();

	string getFileContents (string filename);
	int* countFreq(string filename);

	void print();
	void printCharacterFreq();

};

#endif
