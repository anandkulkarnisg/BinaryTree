#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

bool isIdentical(const BinaryTreeNode<int>* x, const BinaryTreeNode<int>* y)
{
  // if both trees are empty, return true
  if(!x&&!y)
    return(true);

  // if both trees are non-empty and value of their root node matches,
  // recur for their left and right sub-tree
  return((x&&y)&&(x->m_data==y->m_data)&&isIdentical(x->m_leftChild,y->m_leftChild)&&isIdentical(x->m_rightChild, y->m_rightChild));
}

void invertBinaryTree(BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  swap(node->m_leftChild, node->m_rightChild);
  invertBinaryTree(node->m_leftChild);
  invertBinaryTree(node->m_rightChild);
}

bool isSymmetric(const BinaryTreeNode<int>* node)
{
  if(!node)
    return(true); // A null tree is a symmetric tree.

  // Take the left subtree and invert it.
  invertBinaryTree(node->m_leftChild);

  // After inversion check if the binary tree on left Child is same as binary tree on right Side.If so it is symmetric else no.
  bool result=isIdentical(node->m_leftChild, node->m_rightChild);

  // revert the binary Tree left subtree.
  invertBinaryTree(node->m_leftChild);
  return(result);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> vecList={{1,2,2,3,4,4,3},{1,2,2,99,3,99,3},{1,2,2,3,99,99,3,4,99,99,99,99,99,99,4}};
  BinaryTree<int> relaxedTree(false);
  for(const auto& vec : vecList)
  {
    relaxedTree.createFromArray(vec,99);
    cout<<"symmetric status="<<isSymmetric(relaxedTree.getRoot())<<endl;
  }
  return(0);
}
