// CS130A-Project 2
#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <sstream>
using namespace std;

class Node{
  private:
    int weight;
    char value;
    Node * leftChild;
    Node * rightChild;
  public:
    //Constructors
    Node() { weight = 0;
             value = '\0';
             leftChild = rightChild = NULL; }

    Node(int weight, char value) {
                                    this->weight = weight;
                                    this->value = value;
                                    this->leftChild = NULL;
                                    this->rightChild = NULL;
                                 }

    //Getters and Setters
    int getWeight() { return this->weight; }
    void setWeight( int weight ) { this->weight = weight; }

    char getValue() { return this->value; }
    void setValue( char value ) { this->value = value; }

    Node * getLeftChild() { return this->leftChild; }
    void setLeftChild( Node * child ) { this->leftChild = child; }

    Node * getRightChild() { return this->rightChild; }
    void setRightChild( Node * child ) { this->rightChild = child; }
    void print(Node* root){
      cout << root->getValue() << ":" << root->getWeight()<< "\n";
      if (root->getLeftChild()!= NULL)
	{
		cout << "Here is the left subtree:" << endl;
		print(root->getLeftChild());
	}
      if (root->getRightChild() != NULL)
	{	
		cout << "Here is the right subtree:" << endl;
		print(root->getRightChild());
      	}
	return;
    }
    void print() {print(this);}
 
    //Destructor
    /* ~Node() {

            deleteNode( this );
      
            }
    

    //Helper function for the destructor
    void deleteNode( Node * node ) {
                                   if( leftChild != NULL )
                                     deleteNode( node->leftChild );
                                   if( rightChild != NULL )
                                     deleteNode( node->rightChild );
                                   
                                   delete node;
       
                                   }
    */
    //copy constructor and assignment operator	
    Node& operator=(const Node &n) {

                                   if (&n == this){return *this;}
                                   this->weight = n.weight;
                                   this->value = n.value;
                                   this->leftChild = n.leftChild;
                                   this->rightChild = n.rightChild;
                                   return (*this); 
    }
    Node(const Node &n){
                                   this->weight = n.weight;
                                   this->value = n.value;
                                   this->leftChild = n.leftChild;
                                   this->rightChild = n.rightChild; 
    }
};

#endif
