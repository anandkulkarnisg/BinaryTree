#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

void getNoSiblingList(const BinaryTreeNode<int>* node, vector<int>& result)
{
  if(!node)
    return;
  if(!node->m_leftChild&&node->m_rightChild)
    result.emplace_back(node->m_rightChild->m_data);
  if(!node->m_rightChild&&node->m_leftChild)
    result.emplace_back(node->m_leftChild->m_data);
  getNoSiblingList(node->m_leftChild, result);
  getNoSiblingList(node->m_rightChild, result);
}

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,99,4,5,99,99,99,99,99,6,99,99,99};
  BinaryTree<int> tree;
  tree.createFromArray(vec, 99);
  tree.doInOrderTraversal();

  // Identify the list of all nodes [ i.e values ] that do not have siblings.
  vector<int> result;
  result.reserve(tree.size());
  getNoSiblingList(tree.getRoot(), result);
  for(const auto& iter : result)
    cout<<iter<<", ";
  cout<<'\n';
  return(0);
}
