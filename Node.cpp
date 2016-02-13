#include "Node.h"


void Node::deleteNode(Node * node)
{

  if( leftChild != NULL )
    deleteNode( node->leftChild );
  if( rightChild != NULL )
    deleteNode( node->rightChild );

  delete node;

}
