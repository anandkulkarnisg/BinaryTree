#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

void sinkNode(BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  if(node->m_leftChild && node->m_leftChild->m_data!=0)
  {
    swap(node->m_leftChild->m_data, node->m_data);
    sinkNode(node->m_leftChild);
  }
  else if(node->m_rightChild && node->m_rightChild->m_data!=0)
  {
    swap(node->m_rightChild->m_data, node->m_data);
    sinkNode(node->m_rightChild);
  }
}

void sinkZeroNodes(BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  sinkZeroNodes(node->m_leftChild);
  sinkZeroNodes(node->m_rightChild);
  if(!node->m_data) // i.e if node->m_data is 0 condition.
    sinkNode(node);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{0,1,0,99,99,0,2,99,99,99,99,3,4,99,99}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    sinkZeroNodes(tree.getRoot());
    cout<<"After : "<<endl;
    tree.doInOrderTraversal(); 
  }
  return(0);
}
