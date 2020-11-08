#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

BinaryTreeNode<int>* removeBSTKeysRange(BinaryTreeNode<int>* node, const int& low, const int& high)
{
  // We use post order traversal to readjust the tree. 
  if(!node)
    return(nullptr);
  node->m_leftChild=removeBSTKeysRange(node->m_leftChild, low, high);
  node->m_rightChild=removeBSTKeysRange(node->m_rightChild, low, high);
  if(node->m_data<low)
  {
    BinaryTreeNode<int>* rightChild=node->m_rightChild;
    delete(node);
    return(rightChild);
  }
  if(node->m_data>high)
  {
    BinaryTreeNode<int>* leftChild=node->m_leftChild;
    delete(node);
    return(leftChild);
  }
  return(node);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{6,-13,14,99,-8,13,15,99,99,99,99,7,99,99,99},{-12,-14,7}, {-14}, {8,14,20}};
  BinaryTree<int> tree(false); // A relaxed tree which can change itself multiple times.
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase,99);
    // Remove all keys from a BST where the key value is outside the range given.Expected time complexity is O(n).
    tree.setRoot(removeBSTKeysRange(tree.getRoot(), -10, 13));
    if(!tree.isEmpty())
      tree.doInOrderTraversal();
    else
      cout<<"Tree is empty."<<endl;
  }
  return(0);
}
