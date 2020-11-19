#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;
int failReturnItem=-INT_MAX;

void findInOrderPredecessorInternal(const BinaryTreeNode<int>* node, const int& searchItem, int& result, bool& isSet, int& lastVisited)
{
  if(!node)
    return;
  findInOrderPredecessorInternal(node->m_leftChild, searchItem, result, isSet, lastVisited);
  if(node->m_data==searchItem && !isSet)
  {
    result=lastVisited;
    isSet=true;
  }
  else
    lastVisited=node->m_data;
  findInOrderPredecessorInternal(node->m_rightChild, searchItem, result, isSet, lastVisited);
}

int findInOrderPredecessor(const BinaryTreeNode<int>* node, const int& searchItem)
{
  if(!node)
    return(failReturnItem);
  bool isSet=false;
  int result=failReturnItem;
  int lastVisited=failReturnItem;
  findInOrderPredecessorInternal(node, searchItem, result, isSet, lastVisited);  
  return(result);
}

// Expected Algorithmic complexity : O(n)  : Traversal one time.
// Expected auxillary memory complexity : O(1).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{20,8,22,4,12,99,99,99,99,10,14,99,99,99,99}};
  vector<int> searchItems={4, 8, 10, 14, 20, 22};
  BinaryTree<int> tree(false);
  int result;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    for(const auto& searchItem : searchItems)
    {
      result=findInOrderPredecessor(tree.getRoot(), searchItem);
      if(result!=failReturnItem)
        cout<<"The inorder predecessor of "<<searchItem<<" is = "<<result<<endl;
      else
        cout<<"The inorder predecessor of "<<searchItem<<" is not found in bst!!"<<endl;
    }
  }
  return(0);
}
