#include "Node.h"
#include "Heap.h"
#include "Huffman.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

  string filename;
  cout << "Please enter the file name which contains the text: " << endl;
  cin >> filename;
  Huffman * huff = new Huffman(filename);
  cout << "Here are the character counts: " << endl;
  huff->printCharacterFreq();
  cout << "Here is the encoding for the characters created from those freqencies: " << endl;
  huff->print();
  cout << "Goodbye, World!" << endl;

}
