#include<iostream>
#include<string>
#include<algorithm>
#include<BinaryTree.h>

using namespace std;

void invertBinaryTree(BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  swap(node->m_leftChild, node->m_rightChild);
  invertBinaryTree(node->m_leftChild);
  invertBinaryTree(node->m_rightChild);
}

int main(int argc, char* argv[])
{
  vector<int> vec={4,2,7,1,3,6,9};
  BinaryTree<int> tree;
  tree.createFromArray(vec);

  // Invert the binary tree here.
  invertBinaryTree(tree.getRoot());

  // Do the tree traversal now. the tree is inverted in place. 
  // i.e same tree is changed using raw pointer access.
  tree.doInOrderTraversal();

  //Exit here with success.
  return(0);
}
