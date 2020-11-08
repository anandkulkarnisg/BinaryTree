#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void printArrayToConsole(const int pathArr[], const size_t& size)
{
  for(size_t i=0;i<size;++i)
    cout<<pathArr[i]<<", ";
  cout<<pathArr[size]<<'\n'; 
}

void printRootToLeafPaths(const BinaryTreeNode<int>* node, int pathArr[], size_t arrIdx)
{
  if(!node)
    return;

  pathArr[arrIdx]=node->m_data;
  if(isLeaf(node))
    printArrayToConsole(pathArr, arrIdx);
  else
  {
    if(node->m_leftChild)
      printRootToLeafPaths(node->m_leftChild, pathArr, arrIdx+1);
    if(node->m_rightChild)
      printRootToLeafPaths(node->m_rightChild, pathArr, arrIdx+1);
  }
}

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);
  size_t height=tree.height();
  int pathArr[height];

  // Identify and print all root to leaf paths possible in the tree.
  printRootToLeafPaths(tree.getRoot(), pathArr, 0);
  return(0);
}
