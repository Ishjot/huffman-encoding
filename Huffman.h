#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include "Heap.h"

using namespace std;

class Huffman {
private:
	//

public:
	Huffman(string filename);
	//~Huffman();
	string Encode(string input);
	string decode(string input);

	string getFileContents (string filename);
	int* countFreq(string filename);

	//void print(); // for testing?

};

#endif