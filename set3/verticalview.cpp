#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<map>
#include<BinaryTree.h>

using namespace std;

typedef map<long, vector<int>, greater<int>> dmap;

void getVerticalViewInternal(const BinaryTreeNode<int>* node, dmap& vmap, const long attributeTag)
{
  if(!node)
    return;
  auto iter=vmap.find(attributeTag);
  if(iter==vmap.end())
    vmap[attributeTag]=vector<int>(1, node->m_data);
  else
    iter->second.emplace_back(node->m_data);
  getVerticalViewInternal(node->m_leftChild, vmap, attributeTag+1);
  getVerticalViewInternal(node->m_rightChild, vmap, attributeTag-1);
}

void getVerticalView(const BinaryTreeNode<int>* node, vector<int>& results)
{
  dmap vmap;
  getVerticalViewInternal(node, vmap, 0); 
  for(const auto& iter : vmap)
  {
    for(const auto& item : iter.second)
      results.emplace_back(item);
  }
}

// print items of a binary tree in vertical order from left to right.
// Expected Algorithmic complexity : O(n).
// Expected auxillary complexity : O(n) [ to store the elements vertically in by each vertical order ].

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,99,2,99,99,99,3},{1,2,99,3,99,99,99},{1,2,3,4,99,99,5}};
  BinaryTree<int> tree(false);
  vector<int> results;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    results.reserve(testCase.size());
    getVerticalView(tree.getRoot(), results);
    for(const auto& iter : results)
      cout<<iter<<", ";
    cout<<'\n';
    results.clear();
  }
  return(0);
}
