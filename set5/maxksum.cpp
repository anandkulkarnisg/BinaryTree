#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>
#include<stack>
#include<unordered_map>

#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

pair<int, int> doBinaryTreeTraversal(const BinaryTreeNode<int>* node, unordered_map<const BinaryTreeNode<int>*,pair<int, int>>& resultMap, const int& k)
{
  // Edge Case : If the node is null we have reached end simply return (0, 0).
  if(!node)
    return(make_pair<int, int>(0, 0));
  // Edge Case : If the node is leaf node then simply return level as 1 and sum as node value. If the level is same as k add to resultMap.
  if(isLeaf(node))
  {
    if(k==1)
    {
      pair<int, int> result=make_pair<int, int>(1, static_cast<int>(node->m_data));
      resultMap.insert(make_pair(node, result));
    }
  }
  // If not a leaf node then a parent node which sits somewhere in the middle or may be root.
  int currLevel, currSum;
  pair<int, int> leftResult=make_pair<int, int>(0, 0);
  pair<int, int> rightResult=make_pair<int, int>(0, 0);
  if(node->m_leftChild)
    leftResult=doBinaryTreeTraversal(node->m_leftChild, resultMap, k);
  if(node->m_rightChild)
    rightResult=doBinaryTreeTraversal(node->m_rightChild, resultMap, k);
  // Now pick the currLevel as 1+max(leftResultLevel, rightResultLevel);
  currLevel=1+max(leftResult.first, rightResult.first);  
  // Now pick the sum as the current node data + max(left, right);
  currSum=node->m_data+max(leftResult.second, rightResult.second);
  if(currLevel==k)
    resultMap.insert(make_pair(node, make_pair<int, int>(static_cast<int>(currLevel), static_cast<int>(currSum))));
  // Return the node results to the parent calling node.
  return(make_pair<int, int>(static_cast<int>(currLevel), static_cast<int>(currSum)));
}

void identifyMaxKSumInBinaryTree(const BinaryTree<int>& inputTree, const int& k)
{
  unordered_map<const BinaryTreeNode<int>*,pair<int, int>> resultMap;
  pair<int, int> result=doBinaryTreeTraversal(inputTree.getRoot(), resultMap, k);
  if(result.first==k)
    resultMap.insert(make_pair(inputTree.getRoot(), result));
  for(const auto& iter : resultMap)
    cout<<iter.first->m_data<<", "<<iter.second.first<<", "<<iter.second.second<<endl;
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    identifyMaxKSumInBinaryTree(tree, 3); // assume k=3 here.
  }
  return(0);
}
