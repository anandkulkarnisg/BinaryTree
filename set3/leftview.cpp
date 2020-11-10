#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<unordered_map>
#include<BinaryTree.h>

using namespace std;

void getLeftViewInternal(const BinaryTreeNode<int>* node, unordered_map<size_t, pair<long, int>>& hashMap, const long attributeTag, const size_t currentLevel)
{
  if(!node)
    return;
  auto iter=hashMap.find(currentLevel);
  if(iter==hashMap.end())
    hashMap[currentLevel]=make_pair<long, int>(static_cast<long>(attributeTag), static_cast<int>(node->m_data));
  else
  {
    if(attributeTag>=iter->second.first)
    {
      hashMap.erase(currentLevel);
      hashMap[currentLevel]=make_pair<long, int>(static_cast<long>(attributeTag), static_cast<int>(node->m_data));
    }
  }
  getLeftViewInternal(node->m_leftChild, hashMap, attributeTag+1, currentLevel+1);
  getLeftViewInternal(node->m_rightChild, hashMap, attributeTag-1, currentLevel+1);
}

void getLeftView(const BinaryTreeNode<int>* node, vector<int>& results)
{
  unordered_map<size_t, pair<long, int>> hashMap; // hashmap stores in structure level, pair<attributeTag, item>.
  getLeftViewInternal(node, hashMap, 0, 0);
  for(const auto& iter : hashMap)
    results.emplace_back(iter.second.second);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{4,5,2,99,99,3,1,99,99,99,99,6,7,99,99},{1,2,3,4,5,99,6},
                                 {1,2,3,99,4,99,99,99,99,99,5,99,99,99,99,99,99,99,99,99,99,99,6,99,99,99,99,99,99,99,99}
                                };
  BinaryTree<int> tree(false);
  vector<int> results;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    results.reserve(testCase.size()/2);
    getLeftView(tree.getRoot(), results);
    for(const auto& iter : results)
      cout<<iter<<", ";
    cout<<'\n';
    results.clear();
  }
  return(0);
}
