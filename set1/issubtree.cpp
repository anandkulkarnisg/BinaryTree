#include<iostream>
#include<string>
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

bool isSubTree(const BinaryTreeNode<int>* node1, const BinaryTreeNode<int>* node2)
{
  if(!node1)
    return(true);
  if(!node2)
    return(true);
  if(isIdentical(node1, node2))
    return(true);
  return(isIdentical(node1->m_leftChild, node2)||isIdentical(node1->m_rightChild, node2)); 
}

int main(int argc, char* argv[])
{
  vector<vector<int>> m_vec={{1,2,3,4,5,6,7},{3,6,7}};
  BinaryTree<int> tree1, tree2;
  tree1.createFromArray(m_vec[0]);
  tree2.createFromArray(m_vec[1],99);

  // Check if the tree2 is a subtree of tree1.
  bool result=isSubTree(tree1.getRoot(), tree2.getRoot());
  cout<<"The result="<<result<<endl;

  return(0); 
}
