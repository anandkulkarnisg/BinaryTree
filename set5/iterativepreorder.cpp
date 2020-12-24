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

void doIterativePreOrderTraversal(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  cout<<"Iterative PreOrder Traversal : ";
  stack<const BinaryTreeNode<int>*> nodeStack;
  nodeStack.push(node);
  while(!nodeStack.empty())
  {
    const BinaryTreeNode<int>* item=nodeStack.top();
    nodeStack.pop();
    cout<<item->m_data<<", ";
    if(item->m_rightChild)
      nodeStack.push(item->m_rightChild);
    if(item->m_leftChild)
      nodeStack.push(item->m_leftChild);
  }
  cout<<'\n';
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,99,3,4}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    tree.doPreOrderTraversal();
    doIterativePreOrderTraversal(tree.getRoot());
  }
  return(0);
}
