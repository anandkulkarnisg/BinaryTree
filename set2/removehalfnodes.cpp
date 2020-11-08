#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

bool isHalfNode(const BinaryTreeNode<int>* node)
{
  return((node->m_leftChild&&!node->m_rightChild)||(node->m_rightChild&&!node->m_leftChild));
}

BinaryTreeNode<int>* removeHalfNodes(BinaryTreeNode<int>* node)
{
  if(!node||isLeaf(node))
    return(node);
  // Post order traversal : left->right->parent [ O(n) complexity. ]
  node->m_leftChild=removeHalfNodes(node->m_leftChild);
  node->m_rightChild=removeHalfNodes(node->m_rightChild);
  if(isHalfNode(node))
  {
    if(node->m_leftChild)
    {
      BinaryTreeNode<int>* temp=node->m_leftChild;
      delete(node);
      return(temp);
    }
    else
    {
      BinaryTreeNode<int>* temp=node->m_rightChild;
      delete(node);
      return(temp);
    }
  }
  return(node);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,99,5,6,99,7,99,99,8,9,99,99},{1,2,5,3,99,99,99},{2,7,5,99,6,99,9,99,99,1,11,99,99,4,99}};
  BinaryTree<int> tree(false);  // We need a relaxed tree in order to ensure structure of tree can be altered.
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase,99);
    cout<<"before : "<<endl;
    tree.doInOrderTraversal();
    tree.setRoot(removeHalfNodes(tree.getRoot()));
    cout<<"after : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
