#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

void getAuxillaryDiagonalSumInternal(const BinaryTreeNode<int>* node, const size_t verticalLevel, map<size_t, long>& resultMap)
{
  if(!node)
    return;
  resultMap[verticalLevel]+=node->m_data;
  getAuxillaryDiagonalSumInternal(node->m_leftChild, verticalLevel, resultMap);
  getAuxillaryDiagonalSumInternal(node->m_rightChild, verticalLevel+1, resultMap);
}

void getAuxillaryDiagonalSum(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  map<size_t, long> resultMap;
  getAuxillaryDiagonalSumInternal(node, 0, resultMap);
  for(const auto& iter : resultMap)
    cout<<"The auxillary diagonal sum for key = "<<iter.first << " is "<<iter.second<<endl;
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
    getAuxillaryDiagonalSum(tree.getRoot());
  }
  return(0);
}
