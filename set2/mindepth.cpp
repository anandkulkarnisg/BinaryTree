#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<climits>
#include<BinaryTree.h>

using namespace std;

size_t getMinDepth(const BinaryTreeNode<int>* node)
{
  if(!node)
    return(0);
  size_t leftSubTreeHeight=0, rightSubTreeHeight=0;
  if(node->m_leftChild)
    leftSubTreeHeight=1+getMinDepth(node->m_leftChild);
  if(node->m_rightChild)
    rightSubTreeHeight=1+getMinDepth(node->m_rightChild);
  return(min(leftSubTreeHeight, rightSubTreeHeight));
}

// Identify the min depth of a binary tree. This is defined as the number of edges on the shortest path from root to leaf node.
// geeksforgeeks and other sites have some stupudity around this. They count the nodes but that is wrong. This shortest depth is opposite of height of a tree.
// Expected Algorithmic Complexity : O(n).
// Auxillary memory complexity : O(1).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{},{1,2,3,4,5,99,99},{1},{1,2,3,4,5,6,7},{},{1,2,99,3,99,99,99},{1,99,2,99,99,99,3},{}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"minDepth="<<getMinDepth(tree.getRoot())<<endl;
  }
  return(0);
}
