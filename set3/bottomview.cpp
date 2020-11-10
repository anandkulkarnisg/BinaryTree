#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<unordered_map>
#include<BinaryTree.h>

using namespace std;

void getBottomViewInternal(const BinaryTreeNode<int>* node, unordered_map<long, pair<size_t, int>>& hashMap, const long attributeTag, const size_t currentLevel)
{
  if(!node)
    return;
  auto iter=hashMap.find(attributeTag);
  if(iter==hashMap.end())
    hashMap[attributeTag]=make_pair<size_t, int>(static_cast<size_t>(currentLevel),static_cast<int>(node->m_data));
  else
  {
    if(currentLevel>=iter->second.first)
      hashMap[attributeTag]=make_pair<size_t, int>(static_cast<size_t>(currentLevel),static_cast<int>(node->m_data));
  }
  getBottomViewInternal(node->m_leftChild, hashMap, attributeTag+1, currentLevel+1);
  getBottomViewInternal(node->m_rightChild, hashMap, attributeTag-1, currentLevel+1);
}

void getBottomView(const BinaryTreeNode<int>* node, vector<int>& results)
{
  unordered_map<long, pair<size_t, int>> hashMap;
  getBottomViewInternal(node, hashMap, 0, 0);
  for(const auto& iter : hashMap)
  {
    //cout<<"key="<<iter.first<<" and value pair is ="<<iter.second.first<<", "<<iter.second.second<<endl;
    results.emplace_back(iter.second.second);
  }
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{20,8,22,5,3,99,25,99,99,10,14,99,99,99,99},{20,8,22,5,3,4,25,99,99,10,14,99,99,99,99},{1,2,3,4,5,6,7}};
  BinaryTree<int> tree(false);
  vector<int> results;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    results.reserve(testCase.size()/2);
    getBottomView(tree.getRoot(), results);
    for(const auto& iter : results)
      cout<<iter<<", ";
    cout<<'\n';
    results.clear();
  }
  return(0);
}
