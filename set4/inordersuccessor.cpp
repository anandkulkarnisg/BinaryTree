#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

int failReturnItem=-INT_MAX;

void findInOrderSuccessorInternal(const BinaryTreeNode<int>* node, const int& searchItem,int& result, bool& isSet,int& lastVisited)
{
  if(!node)
    return;
  findInOrderSuccessorInternal(node->m_leftChild, searchItem, result, isSet, lastVisited);
  if(lastVisited==searchItem && !isSet)
  {
    result=node->m_data;
    isSet=true;
  }
  else
    lastVisited=node->m_data;
  findInOrderSuccessorInternal(node->m_rightChild, searchItem, result, isSet, lastVisited);
}

int findInOrderSuccessor(const BinaryTreeNode<int>* node, const int& searchItem)
{
  if(!node)
    return(failReturnItem); // Assume -INT_MAX as a number returned on failure to search.
  int result=failReturnItem;
  bool isSet=false;
  int lastVisited=failReturnItem;
  findInOrderSuccessorInternal(node, searchItem, result, isSet, lastVisited);
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
      result=findInOrderSuccessor(tree.getRoot(), searchItem);
      if(result!=failReturnItem)
        cout<<"The inorder successor of "<<searchItem<<" is = "<<result<<endl;
      else
        cout<<"The inorder successor of "<<searchItem<<" is not found in bst!!"<<endl;
    }
  }
  return(0);
}
