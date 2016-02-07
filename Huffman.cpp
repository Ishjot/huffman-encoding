#include "Huffman.h"
#include <fstream>
#include <streambuf>
#include <cstdlib>

/*Huffman::Huffman(string filename){
	
}*/

string Huffman::getFileContents(string filename) {
	//read the input file into a stream object
	ifstream myFile(filename.c_str());
	if (!myFile){
		cerr << "Could not open file " << filename << ". Exit now!" << endl;
		exit(1); 
	}
	return string((istreambuf_iterator<char>(myFile)),istreambuf_iterator<char>());
}

int* Huffman::countFreq(string filename){
	string getContent = getFileContents(filename);
	int* arrayOfCounts = new int[27];
	for (int i = 0; i < 27; i++){
		arrayOfCounts[i] = 0;
	}
	for (int i = 0; i< getContent.length(); i++){
		int index = (int) getContent[i] - (int) ('a');
		if (getContent[i] == ' '){
			index = 26;
		}
		arrayOfCounts[index]++;
	}
	return arrayOfCounts;
}



