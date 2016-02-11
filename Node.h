// CS130A-Project 2
#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

class Node{
  private:
    int weight;
    char value;
    Node * leftChild;
    Node * rightChild;
  public:
    //Constructors
    Node() { weight = value = leftChild = rightChild = 0 }
    Node(int weight, char value) : weight(weight), value(value) { }

    //Getters and Setters
    int getWeight() { return this->weight; }
    void setWeight( int weight ) { this->weight = weight; }

    char getValue() { return this->value; }
    void setValue( char value ) { this->value = value; }

    Node * getLeftChild() { return this->leftChild; }
    void setLeftChild( Node * child ) { this->leftChild = child }

    Node * getRightChild() { return this->rightChild; }
    void setRightChild( Node * child ) { this->rightChild = child }
 
    //Destructor
    ~Node();
    //TODO: Add copy and assignment operator	
};

#endif
