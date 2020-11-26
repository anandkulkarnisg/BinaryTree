#include<algorithm>
#include<climits>
#include<iostream>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

pair<BinaryTreeNode<int>*, long> removePathSumInternal(BinaryTreeNode<int>* node, const long& k, const long currSum)
{
  if(!node)
    return(make_pair<BinaryTreeNode<int>*, long>(nullptr, static_cast<long>(currSum)));
  pair<BinaryTreeNode<int>*, long> leftResult=removePathSumInternal(node->m_leftChild, k, node->m_data+currSum);
  pair<BinaryTreeNode<int>*, long> rightResult=removePathSumInternal(node->m_rightChild, k, node->m_data+currSum);
  node->m_leftChild=leftResult.first;
  node->m_rightChild=rightResult.first;
  long currResult=max(leftResult.second, rightResult.second);
  if(currResult<k)
  {
    //cout<<"deleting the node = "<<node->m_data<<endl;
    delete(node);
    return(make_pair<BinaryTreeNode<int>*, long>(nullptr, static_cast<long>(currResult)));
  }
  return(make_pair<BinaryTreeNode<int>*, long>(static_cast<BinaryTreeNode<int>*>(node), static_cast<long>(currResult)));
}

void removepathsumlessk(BinaryTree<int>& tree, const long& k)
{
  pair<BinaryTreeNode<int>*, long> resultPair=removePathSumInternal(tree.getRoot(), k, 0);
  tree.setRoot(resultPair.first);
}

int main(int argc, char* argv[])
{
  vector<size_t> idxList={0,1,2,5,6,11,14,24,29,59};vector<int> valList={1,2,3,4,5,6,7,8,9,10};
  BinaryTree<int> tree(false);
  vector<long> testCases={4, 10, 15, 23, 34, 35, 36};
  for(const auto& testCase : testCases)
  {
    tree.createFromLevelArray(idxList, valList);
    cout<<"Before : with k = "<<testCase<<endl;
    tree.doInOrderTraversal();
    removepathsumlessk(tree, testCase);
    cout<<"After : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
