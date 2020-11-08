#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

void doLevelOrderTraversalInternal(const BinaryTreeNode<int>* node, const int& currLevel, const int& inputLevel)
{
  if(currLevel>inputLevel)
    return;
  if(node&&currLevel==inputLevel)
    cout<<node->m_data<<",";
  if(node->m_leftChild)
    doLevelOrderTraversalInternal(node->m_leftChild,1+currLevel,inputLevel);
  if(node->m_rightChild)
    doLevelOrderTraversalInternal(node->m_rightChild,1+currLevel,inputLevel);
}

void doLevelOrderTraversal(const BinaryTreeNode<int>* node, const int& inputLevel)
{
  if(!node)
    return;
  doLevelOrderTraversalInternal(node, 0, inputLevel);
}

int main(int argc, char* argv[])
{
  BinaryTree<int> tree(false);  // use a relaxed tree.
  vector<int> vec={1,2,3,4,5,6,7};
  tree.createFromArray(vec);

  // Now attempt to implement the level order traversal algorithm. We assume level at root is zero. And then onwards continues.
  doLevelOrderTraversal(tree.getRoot(), 2);

  // How to traverse all level one by one ?. Simple get the height of the tree and iteratively call the level order traversal.
  cout<<'\n'<<"printing the full binary tree level by level"<<'\n';
  for(unsigned int level=0; level<1+tree.height();++level)
    doLevelOrderTraversal(tree.getRoot(), level);
  cout<<endl;
  return(0);
}
