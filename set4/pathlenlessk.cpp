#include<algorithm>
#include<climits>
#include<iostream>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  if(!node->m_leftChild&&!node->m_rightChild)
    return(true);
  return(false);
}

BinaryTreeNode<int>* removeShortPathNodesUtil(BinaryTreeNode<int>* root, int level, int k) 
{ 
  if(!root)
    return(nullptr);

  root->m_leftChild=removeShortPathNodesUtil(root->m_leftChild, level + 1, k);
  root->m_rightChild=removeShortPathNodesUtil(root->m_rightChild, level + 1, k);
  if(isLeaf(root)&&level<k)
  {
    delete(root);
    return(nullptr);
  }
  return(root);
}

BinaryTreeNode<int>* removeShortPathNodes(BinaryTreeNode<int>* root, long k)
{ 
  return(removeShortPathNodesUtil(root, 1, k));
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,99,6,7,99,99,99,99,99,8,99},{1,2,3}};
  BinaryTree<int> tree(false);
  long k=4;
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    tree.setRoot(removeShortPathNodes(tree.getRoot(),k));
    cout<<"After : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
