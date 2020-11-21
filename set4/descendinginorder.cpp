#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<BinaryTree.h>

using namespace std;

void doReverseInOrder(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  doReverseInOrder(node->m_rightChild);
  cout<<node->m_data<<", ";
  doReverseInOrder(node->m_leftChild);
}

int main(int argc, char* argv[])
{
  vector<int> vec={4,2,6,1,3,5,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);
  tree.doInOrderTraversal();
  cout<<"Reverse InOrder Traversal : ";
  doReverseInOrder(tree.getRoot());
  cout<<'\n';
  return(0);
}
