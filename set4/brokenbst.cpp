#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

// Repair a broken BST where only two nodes are misplaced. The idea is to identify them and swap to restore BST.
// Expected algorithmic complexity : O(n).
// Expected Auxillary Complexity O(1).

void inOrderTraversal(BinaryTreeNode<int>* node,BinaryTreeNode<int>** prev,BinaryTreeNode<int>** first,BinaryTreeNode<int>** middle,BinaryTreeNode<int>** last)
{
  if(!node)
    return;
  inOrderTraversal(node->m_leftChild, prev, first, middle, last);
  if(*prev && node->m_data<(*prev)->m_data)
  {
    if(!*first)
    {
      *first=*prev;
      *middle=node;
    }
    else
      *last=node;
  }
  *prev=node;
  inOrderTraversal(node->m_rightChild, prev, first, middle, last);
}

void recoverBrokenBST(BinaryTreeNode<int>* node)
{
  BinaryTreeNode<int> *first, *middle, *last, *prev;
  first=middle=last=prev=NULL;
  inOrderTraversal(node, &prev, &first, &middle, &last);
  if(first&&last)
  {
    int temp=first->m_data;
    first->m_data=last->m_data;
    last->m_data=temp;
  }
  else if(first&&middle)
  {
    int temp=first->m_data;
    first->m_data=middle->m_data;
    middle->m_data=temp;
  }
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{10,5,8,2,20,99,99},{10,5,22,2,8,18,20},{7,5,9,10,6,8,4}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {    
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    recoverBrokenBST(tree.getRoot());
    cout<<"After : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
