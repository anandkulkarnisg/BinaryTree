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

size_t getGrandParentNodesInternal(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet)
{
  if(!node)
    return(0);
  size_t leftTreeHeight=0, rightTreeHeight=0;
  if(node->m_leftChild)
    leftTreeHeight=1+getGrandParentNodesInternal(node->m_leftChild, hashSet);
  if(node->m_rightChild)
    rightTreeHeight=1+getGrandParentNodesInternal(node->m_rightChild, hashSet);
  size_t returnHeight=max(leftTreeHeight, rightTreeHeight);
  if(returnHeight>1)
    hashSet.insert(&node->m_data);
  return(returnHeight);  
}

void getGrandParentNodes(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet)
{
  if(!node)
    return;
  getGrandParentNodesInternal(node, hashSet);
}

// grand parents function returns nodes that have children ( atleast one ) and their children ( atleast one ).
// Big O Complexity : O(n).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,99,2,99,99,99,3},{1,2,3}};
  BinaryTree<int> tree(false);
  unordered_set<const int*> hashSet;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    getGrandParentNodes(tree.getRoot(), hashSet);
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
