#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

size_t getBinaryTreeHeight(const BinaryTreeNode<int>* node)
{
  if(!node||isLeaf(node))
    return(0);

  size_t leftSubTreeHeight=0, rightSubTreeHeight=0;
  if(node->m_leftChild)
    leftSubTreeHeight=1+getBinaryTreeHeight(node->m_leftChild);
  if(node->m_rightChild)
    rightSubTreeHeight=1+getBinaryTreeHeight(node->m_rightChild);
  return(max(leftSubTreeHeight, rightSubTreeHeight));
}

void getBTDiameterInternal(const BinaryTreeNode<int>* node, size_t& maxSize)
{
  if(!node||isLeaf(node))
    return;

  size_t leftSubTreeHeight=0,rightSubTreeHeight=0;
  if(node->m_leftChild)
    leftSubTreeHeight=1+getBinaryTreeHeight(node->m_leftChild);

  if(node->m_rightChild)
    rightSubTreeHeight=1+getBinaryTreeHeight(node->m_rightChild);

  if((leftSubTreeHeight+rightSubTreeHeight)>maxSize)
    maxSize=leftSubTreeHeight+rightSubTreeHeight;
}

size_t getDiameter(const BinaryTreeNode<int>* node)
{
  size_t diameter=0;
  getBTDiameterInternal(node, diameter);
  return(diameter);
}

// get diameter of a binary tree. This is also the longest distance between two nodes in a tree.
int main(int argc, char* argv[])
{
  BinaryTree<int> tree;
  vector<int> vec={1, 2, 3, 4, 5, 99, 99};
  tree.createFromArray(vec, 99);
  size_t diameter=getDiameter(tree.getRoot());
  cout<<"diameter="<<diameter<<endl;
  return(0);
}
