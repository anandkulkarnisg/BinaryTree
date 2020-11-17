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

void getGrandChildrenNodesInternal(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet, const size_t level)
{
  if(!node)
    return;
  if(level>1)
    hashSet.insert(&node->m_data); 
  getGrandChildrenNodesInternal(node->m_leftChild, hashSet, level+1);
  getGrandChildrenNodesInternal(node->m_rightChild, hashSet, level+1);
}

void getGrandChildrenNodes(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet)
{
  getGrandChildrenNodesInternal(node, hashSet, 0);
}

// grand children function returns nodes that are grand children.A grand child node has a parent node and a parent-parent node.
// Big O Complexity : O(n).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,99,2,99,99,99,3},{1,2,3},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  BinaryTree<int> tree(false);
  unordered_set<const int*> hashSet;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    getGrandChildrenNodes(tree.getRoot(), hashSet);
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
