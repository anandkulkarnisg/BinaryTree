#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

typedef unordered_map<size_t, pair<long, int>> lmap;

void getCornerNodesInternal(const BinaryTreeNode<int>* node, lmap& leftMap, lmap& rightMap, const size_t currLevel, const long propertyIdx, const bool& isLeft)
{
  if(!node)
    return;
  if(propertyIdx>=0&&isLeft)
  {
    auto leftIter=leftMap.find(currLevel);
    if(leftIter==leftMap.end())
      leftMap[currLevel]=make_pair<long, int>(static_cast<long>(propertyIdx), static_cast<int>(node->m_data));
    else
    {
      if(leftIter->second.first<=propertyIdx)
      {
        leftMap.erase(currLevel);
        leftMap[currLevel]=make_pair<long, int>(static_cast<long>(propertyIdx), static_cast<int>(node->m_data));
      }
    }
  }
  else
  {
    auto rightIter=rightMap.find(currLevel);
    if(rightIter==rightMap.end())
      rightMap[currLevel]=make_pair<long, int>(static_cast<long>(propertyIdx), static_cast<int>(node->m_data));
    else
    {
      if(rightIter->second.first>=propertyIdx)
      {
        rightMap.erase(currLevel);
        rightMap[currLevel]=make_pair<long, int>(static_cast<long>(propertyIdx), static_cast<int>(node->m_data));
      }
    }
  }
  getCornerNodesInternal(node->m_leftChild, leftMap, rightMap, currLevel+1, propertyIdx+1, true);
  getCornerNodesInternal(node->m_rightChild, leftMap, rightMap, currLevel+1, propertyIdx-1, false);
}

void printCornerNodes(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  lmap leftMap, rightMap;
  unordered_set<int> results;
  getCornerNodesInternal(node, leftMap, rightMap, 0, 0, true);
  for(const auto& mapIter : leftMap)
    results.insert(mapIter.second.second);
  for(const auto& mapIter : rightMap)
    results.insert(mapIter.second.second);
  cout<<"The Corner nodes are : ";
  for(const auto& iter : results)
    cout<<iter<<", ";
  cout<<'\n';
}

// Algorithmic complexity is : O(n), Auxillary Memory Complexity : O(log(n)) for height balanced tree, O(n) for a worst case degenerate tree.
int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,3,99,4,5,99},{1,2,3,4,99,99,5}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    printCornerNodes(tree.getRoot());
  }
  return(0);
}
