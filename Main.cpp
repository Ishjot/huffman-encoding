#include "Node.h"
#include "Heap.h"
#include "Huffman.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

  Huffman * huff = new Huffman("plain.input");
  cout << "Here are the character counts: " << endl;
  huff->printCharacterFreq();
  cout << "Here is the encoding for the characters created from those freqencies: " << endl;
  huff->encode();
  huff->decode("encoded.input");
  cout << "Goodbye, World!" << endl;

  return 0;

}
