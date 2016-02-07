CXX = g++
#CXX = clang++
#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = Heap Huffman

#all: Main.o Heap.o Huffman.o
#	${CXX} -g Heap.o Huffman.o Main.o -o prog2

#Main.o: Main.cpp
#	${CXX} -c Main.cpp

#Heap.o: Heap.cpp
#	${CXX} -c Heap.cpp

#Huffman.o: Huffman.cpp
#	${CXX} -c Huffman.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}