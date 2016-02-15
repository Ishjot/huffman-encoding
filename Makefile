CXX = g++
#CXX = clang++

CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES = Heap Huffman

all: Main.o Heap.o Huffman.o
	${CXX} -Wall -g Heap.o Huffman.o Main.o -o prog2

Main.o: Main.cpp
	${CXX} -Wall -g -c Main.cpp

Heap.o: Heap.cpp
	${CXX} -Wall -g -c Heap.cpp

Huffman.o: Huffman.cpp
	${CXX} -Wall -g -c Huffman.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
