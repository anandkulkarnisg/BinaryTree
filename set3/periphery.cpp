#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<utility>
#include<unordered_map>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void getPeripheryItemsInternal(const BinaryTreeNode<int>* node, unordered_map<size_t, pair<long, const int*>>& leftViewHashMap,
    unordered_map<size_t, pair<long, const int*>>& rightViewHashMap, unordered_set<const int*>& hashSet,
    const size_t currentLevel, const long attributeTag)
{
  if(!node)
    return;
  if(isLeaf(node))
    hashSet.insert(&node->m_data);

  auto iter1=leftViewHashMap.find(currentLevel);
  auto iter2=rightViewHashMap.find(currentLevel);

  if(iter1==leftViewHashMap.end())
    leftViewHashMap[currentLevel]=make_pair<long, const int*>(static_cast<long>(attributeTag), static_cast<const int*>(&node->m_data));
  else
  {
    if(attributeTag>=iter1->second.first)
    {
      leftViewHashMap.erase(currentLevel);
      leftViewHashMap[currentLevel]=make_pair<long, const int*>(static_cast<long>(currentLevel), static_cast<const int*>(&node->m_data));
    }
  }
  if(iter2==rightViewHashMap.end())
    rightViewHashMap[currentLevel]=make_pair<long, const int*>(static_cast<long>(currentLevel), static_cast<const int*>(&node->m_data));
  else
  {
    if(attributeTag<=iter2->second.first)
    {
      rightViewHashMap.erase(currentLevel);
      rightViewHashMap[currentLevel]=make_pair<long, const int*>(static_cast<long>(currentLevel), static_cast<const int*>(&node->m_data));
    }
  }
  // Invoke further recursion for left and right childs.
  getPeripheryItemsInternal(node->m_leftChild, leftViewHashMap, rightViewHashMap, hashSet, currentLevel+1, attributeTag+1);
  getPeripheryItemsInternal(node->m_rightChild, leftViewHashMap, rightViewHashMap, hashSet, currentLevel+1, attributeTag-1);
}

void getPeripheryItems(const BinaryTreeNode<int>* node, unordered_set<const int*>& hashSet)
{
  if(!node)
    return;
  unordered_map<size_t, pair<long, const int*>> leftViewHashMap, rightViewHashMap;
  getPeripheryItemsInternal(node, leftViewHashMap, rightViewHashMap, hashSet, 0, 0);
  for(const auto& iter : leftViewHashMap)
    hashSet.insert(iter.second.second);
  for(const auto& iter : rightViewHashMap)
    hashSet.insert(iter.second.second);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={
    {1,2,3,4,5,6,7},{1,2,3,4,5,6,7,99,99,8,99,99,9,99,10},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
                                                            16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,
                                                            46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63},{1,2,3,99,4,99,99,99,99,5,99,99,99,99,99},
    {1,2,3,3,4,2,3,99,99,6,7,99,99,99,99},                                                        
    {20,8,22,4,12,99,25,99,99,10,14,99,99,99,99},
    {20,8,22,99,12,99,25,99,99,10,14,99,99,99,99},
  };
  BinaryTree<int> tree(false);
  // HashSet is used to store unique pointer/address locations of items. This helps in handling duplicate values in binary tree which could be present.
  unordered_set<const int*> hashSet;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    hashSet.reserve(testCase.size()/2);
    getPeripheryItems(tree.getRoot(), hashSet);
    for(const auto& iter : hashSet)
      cout<<*iter<<", ";
    cout<<'\n';
    hashSet.clear();
  }
  return(0);
}
