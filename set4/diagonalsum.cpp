#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

void getDiagonalSumInternal(const BinaryTreeNode<int>* node, const size_t verticalLevel, map<size_t, long>& resultMap)
{
  if(!node)
    return;
  auto iter=resultMap.find(verticalLevel);
  if(iter==resultMap.end())
    resultMap[verticalLevel]=node->m_data;
  else
    resultMap[verticalLevel]+=node->m_data;
  getDiagonalSumInternal(node->m_leftChild, verticalLevel+1, resultMap);
  getDiagonalSumInternal(node->m_rightChild, verticalLevel, resultMap);
}

void getDiagonalSum(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  map<size_t, long> resultMap;
  getDiagonalSumInternal(node, 0, resultMap);
  for(const auto& iter : resultMap)
    cout<<"The diagonal sum for key = "<<iter.first << " is "<<iter.second<<endl;
}

// Expected Algorithmic complexity : O(n)  : Traversal one time.
// Expected auxillary memory complexity : O(1).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,9,6,4,5,99,10,11,99,12,7,99,99},{1,2,3,4,5,6,7}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    tree.doInOrderTraversal();
    getDiagonalSum(tree.getRoot());
  }
  return(0);
}
