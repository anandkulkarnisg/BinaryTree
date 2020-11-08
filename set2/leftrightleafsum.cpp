#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

void leftOrRightNodeSum(const BinaryTreeNode<int>* node, const bool& flag, long& sum)
{
  if(!node)
    return;
  if(!flag)
  {
    if(node->m_leftChild)
      sum+=node->m_leftChild->m_data;
  }
  else
  {
    if(node->m_rightChild)
      sum+=node->m_rightChild->m_data;
  }
  leftOrRightNodeSum(node->m_leftChild, flag, sum);
  leftOrRightNodeSum(node->m_rightChild, flag, sum);
}

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);

  // Find the sum of all left leaf or right leaf of a given binary Tree.A bool is passed and if it is false then left leaf else right leaf.
  long leftSum=0, rightSum=0;
  leftOrRightNodeSum(tree.getRoot(),false, leftSum);
  leftOrRightNodeSum(tree.getRoot(),true, rightSum);
  cout<<"The sum of the left nodes is = "<<leftSum<<endl;
  cout<<"The sum of right nodes is = "<<rightSum<<endl;
  return(0);
}
