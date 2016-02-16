#include "Node.h"
#include "Heap.h"
#include "Huffman.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

  Huffman * huff = new Huffman("plain.input");
  huff->encode();  
  huff->printEncoded( "plain.input" );
  cout << endl;
  huff->decode("encoded.input");
  return 0;

}
