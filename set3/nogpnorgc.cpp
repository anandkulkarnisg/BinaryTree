#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<unordered_map>
#include<BinaryTree.h>

using namespace std;

size_t getNoGPNorGC(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet, const size_t level)
{
  if(!node)
    return(0);
  size_t leftTreeHeight=0, rightTreeHeight=0;
  if(node->m_leftChild)
    leftTreeHeight=1+getNoGPNorGC(node->m_leftChild, hashSet, level+1);
  if(node->m_rightChild)
    rightTreeHeight=1+getNoGPNorGC(node->m_rightChild, hashSet, level+1);
  size_t returnHeight=max(leftTreeHeight, rightTreeHeight);
  if(returnHeight<2 && level<2)
    hashSet.insert(&node->m_data);
  return(returnHeight);
}

void getNeitherGrandParentNorGrandChildNodes(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet)
{
  getNoGPNorGC(node, hashSet, 0);
}

// Get all those nodes that are neither grand parents nor grand children.
// Grand parent : you have a child node and a child-child node [ atleast one ].
// Grand children node : you have a parent and parent-parent node.
// Big O Complexity : O(n).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,99,2,99,99,99,3},{1,2,3},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  BinaryTree<int> tree(false);
  unordered_set<const int*> hashSet;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    getNeitherGrandParentNorGrandChildNodes(tree.getRoot(), hashSet);
    if(!hashSet.size())
      cout<<"Empty!!"<<endl;
    else
    {
      for(const auto& iter : hashSet)
        cout<<*iter<<", ";
      cout<<'\n';
      hashSet.clear();
    }
  }
  return(0);
}
