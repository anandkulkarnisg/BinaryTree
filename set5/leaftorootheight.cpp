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

void printRootToLeafPathsOnlyHeight(const BinaryTreeNode<int>* node, int pathArr[], size_t arrIdx, const size_t& height,bool& terminate)
{
  if(!node||terminate)
    return;

  pathArr[arrIdx]=node->m_data;
  if(isLeaf(node)&&arrIdx==height) // Here we check that the node is last leaf node and this one is the path that is the height of the tree.
  {
    printArrayToConsole(pathArr, arrIdx);
    terminate=true;
    return;
  }
  else
  {
    if(node->m_leftChild)
      printRootToLeafPathsOnlyHeight(node->m_leftChild, pathArr, arrIdx+1, height, terminate);
    if(node->m_rightChild)
      printRootToLeafPathsOnlyHeight(node->m_rightChild, pathArr, arrIdx+1, height, terminate);
  }
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7,99,99,8,99,99,99,99,99}, {1,2,3,4,5,6,7}};
  BinaryTree<int> tree(false); // Set the tree up for a relaxed mode where it can be changed.
  for(const auto& testCase : testCases) {
      tree.createFromArray(testCase, 99);  // Use 99 as a null value while building the binary tree.
      size_t height = tree.height();
      int pathArr[height];
      bool terminate = false;
      // Identify and print root to leaf paths possible in the tree which is on the height path [ i.e the longest root to leaf node path ].
      printRootToLeafPathsOnlyHeight(tree.getRoot(), pathArr, 0, height, terminate);
  }
  return(0);
}