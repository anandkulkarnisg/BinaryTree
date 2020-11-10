#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<unordered_map>
#include<BinaryTree.h>

using namespace std;

void getTopLevelViewInternal(const BinaryTreeNode<int>* node, unordered_map<long, pair<size_t, int>>& hashMap, const long propertyTag,const size_t currentLevel)
{
  if(!node)
    return;
  long currTag=propertyTag;
  size_t currLevel=currentLevel;
  auto iter=hashMap.find(currTag);
  if(iter==hashMap.end())
    hashMap[currTag]=make_pair<size_t, int>(static_cast<size_t>(currLevel), static_cast<int>(node->m_data));
  else
  {
    if(currentLevel<iter->second.first)
      hashMap[currTag]=make_pair<size_t, int>(static_cast<size_t>(currLevel), static_cast<int>(node->m_data));
  }
  getTopLevelViewInternal(node->m_leftChild, hashMap, currTag+1, 1+currentLevel);
  getTopLevelViewInternal(node->m_rightChild, hashMap, currTag-1, 1+currentLevel);
}

void getTopView(const BinaryTreeNode<int>* node, vector<int>& results)
{
  unordered_map<long, pair<size_t, int>> hashMap;
  getTopLevelViewInternal(node, hashMap, 0, 0);
  for(const auto& iter : hashMap)
    results.emplace_back(iter.second.second);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7}, {1,2,3,99,4,99,99,99,99,99,5,99,99,99,99,99,99,99,99,99,99,99,6,99,99,99,99,99,99,99,99},
                                 {1,99,2,99,99,99,3},{1,2,3,99,4,5,99}
                                };
  BinaryTree<int> tree(false);
  vector<int> results;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    results.reserve(testCase.size()/2);
    getTopView(tree.getRoot(), results);
    for(const auto& iter : results)
      cout<<iter<<", ";
    cout<<'\n';
    results.clear();
  }
  return(0);
}
