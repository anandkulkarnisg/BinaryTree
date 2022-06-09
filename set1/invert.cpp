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

// Expected Algorithmic Complexity : O(n), Auxiliary Memory Complexity : O(1).
// Additional Note : If a BST is inverted it produces a BST which is in reverse sorted order. Ex:- last testCase below. [ ascending to descending ].

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{4,2,7,1,3,6,9},{4,2,6,1,3,5,7}};
  BinaryTree<int> tree(false);

  for(const auto& testCase : testCases)
  {
    // Create a Tree first.
    tree.createFromArray(testCase);

    // Invert the binary tree here.
    invertBinaryTree(tree.getRoot());

    // Do the tree traversal now. the tree is inverted in place. 
    // i.e same tree is changed using raw pointer access.
    tree.doInOrderTraversal();
  }

  //Exit here with success.
  return(0);
}