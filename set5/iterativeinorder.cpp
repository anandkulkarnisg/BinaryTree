#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>
#include<stack>

#include<BinaryTree.h>

using namespace std;

void doIterativeInOrderTraversal(const BinaryTreeNode<int>* node)
{ 
  stack<const BinaryTreeNode<int>*> nodeStack;
  const BinaryTreeNode<int>* curr=node;
  cout<<"Iterative InOrder Traversal : ";
  while(curr||!nodeStack.empty()) 
  {
    /* Reach the left most Node of the curr Node */
    while(curr)
    {
      /* place pointer to a tree node on the stack before traversing the node's left subtree */
      nodeStack.push(curr);
      curr=curr->m_leftChild;
    }
    /* Current must be NULL at this point */
    curr=nodeStack.top();
    nodeStack.pop();
    cout<<curr->m_data<<", ";
    /* we have visited the node and its left subtree.  Now, it's right subtree's turn */
    curr=curr->m_rightChild;
  } /* end of while */
  cout<<'\n';
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,99,3,4}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    tree.doInOrderTraversal();
    doIterativeInOrderTraversal(tree.getRoot());
  }
  return(0);
}
