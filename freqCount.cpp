#include "freqCounter.h"
#include <fstream>
#include <streambuf>
#include <cstdlib>

freqCounter::freqCounter(){
	arrayOfCounts = new int[27];
	for (int i = 0; i < 27; i++){
		arrayOfCounts[i] = 0;
	}
}

string freqCounter::getFileContents(string filename) {
	//read the input file into a stream object
	ifstream myFile(filename.c_str());
	if (!myFile){
		cerr << "Could not open file " << filename << ". Exit now!" << endl;
		exit(1); 
	}
	return string((istreambuf_iterator<char>(myFile)),istreambuf_iterator<char>());
}

void freqCounter::countFreq(string filename){
	string getContent = getFileContents(filename);
	for (int i = 0; i< getContent.length(); i++){
		int index = (int) getContent[i] - (int) ('a');
		if (getContent[i] == ' '){
			index = 26;
		}
		arrayOfCounts[index]++;
	}
	return;
}

// uncomment to test it out
/*
int main()
{
	freqCounter fc;
	fc.countFreq("test1.txt");
	int* testArray = fc.getArrayOfCounts();
	char ch = "a";
	for (int i=0; i< 27; i++){
	   char ch2 = ch + (char)i;
	   if (i == 26){
	   	ch2 = " ";
	   }
	   cout << ch2 << " " << testArray[i] << endl;
	}

	return 0;
}
*/