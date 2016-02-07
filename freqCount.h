// CS130A-Project 2
#ifndef FREQCOUNTER_H_
#define FREQCOUNTER_H_

#include <iostream>
#include <string>
using namespace std;

class freqCounter{
 private:
  int* arrayOfCounts;

 public:
  // constructor
  freqCounter();
  
  // read the file content into a string
  string getFileContents (string filename);

  // Count the frequencies of every character in the file
  // increment the count and store the value in the corresponding index
  void countFreq(string filename);

  int* getArrayOfCounts() {return arrayOfCounts;}
  

};

#endif
