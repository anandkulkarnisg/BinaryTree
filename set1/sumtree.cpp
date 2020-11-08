#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void isSumTreeInternal(const BinaryTreeNode<int>* node, size_t& violations)
{
  if(!node||isLeaf(node))
    return;
  int subTreeTotals=0;
  if(node->m_leftChild)
  {
    isSumTreeInternal(node->m_leftChild, violations);
    subTreeTotals=node->m_leftChild->m_data;
  }
  if(node->m_rightChild)
  {
    isSumTreeInternal(node->m_rightChild, violations);
    subTreeTotals+=node->m_rightChild->m_data;
  }
  if(node->m_data!=subTreeTotals)
  {
    ++violations;
    return;
  }
}

bool isSumTree(const BinaryTreeNode<int>* node)
{
  size_t violations=0;
  isSumTreeInternal(node, violations);
  return(violations==0);
}

int main(int argc, char* argv[])
{
  // First Example : This is a sumTree.
  vector<vector<int>> vecs={{10,3,7,1,2,3,4}, {3,2,2}};
  BinaryTree<int> tree(false);  // so that tree is relaxed and can be altered and reconstructed many times.
  for(const auto& vec : vecs)
  {
    tree.createFromArray(vec);
    cout<<"The sumTree status="<<isSumTree(tree.getRoot())<<endl;
  }
  return(0);
}
