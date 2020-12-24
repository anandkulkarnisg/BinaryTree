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

void doIterativePostOrderTraversal(const BinaryTreeNode<int>* root)
{
  // Check for empty tree
  if(!root)
    return;
  stack<const BinaryTreeNode<int>*> nodeStack;
  cout<<"Iterative PostOrder Traversal : ";
  do
  {
    // Move to leftmost node.
    while(root)
    {
      // Push root's right child and then root to stack.
      if(root->m_rightChild)
        nodeStack.push(root->m_rightChild);
      nodeStack.push(root);
      // Set root as root's left child 
      root=root->m_leftChild;
    }
    // Pop an item from stack and set it as root     
    root=nodeStack.top();
    nodeStack.pop();
    // If the popped item has a right child and the right child is not 
    // processed yet, then make sure right child is processed before root 
    if(root->m_rightChild&&!nodeStack.empty()&&nodeStack.top()==root->m_rightChild)
    {
      nodeStack.pop(); // remove right child from stack 
      nodeStack.push(root); // push root back to stack 
      root=root->m_rightChild; // change root so that the right 
      // child is processed next
    }
    else // Else print root's data and set root as NULL 
    {
      cout<<root->m_data<<", ";
      root=nullptr;
    }
  } while(!nodeStack.empty());
  cout<<'\n';
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,99,3,4,99,99},{1,2,3,4,99,99,5}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    tree.doPostOrderTraversal();
    doIterativePostOrderTraversal(tree.getRoot());
  }
  return(0);
}
