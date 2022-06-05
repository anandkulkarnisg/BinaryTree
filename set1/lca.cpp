#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

const BinaryTreeNode<int>* findLCA(const BinaryTreeNode<int>* node, const int& item1, const int& item2)
{
  if(!node)
    return(nullptr);
  if(node->m_data==item1||node->m_data==item2)
    return(node);
  const BinaryTreeNode<int>* leftLca=findLCA(node->m_leftChild, item1, item2);
  const BinaryTreeNode<int>* rightLca=findLCA(node->m_rightChild, item1, item2);
  if(leftLca&&rightLca)
    return(node);
  return(leftLca?leftLca:rightLca);
}

int main(int argc, char* argv[])
{
  vector<tuple<int, int>> tupleTestList={make_tuple<int, int>(4, 5), make_tuple<int, int>(6, 7), make_tuple<int, int>(4, 7), make_tuple<int, int>(4, 11), make_tuple<int, int>(8, 9)};
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);
  for(const auto& tupleItem : tupleTestList)
  {
    const BinaryTreeNode<int>* lca=findLCA(tree.getRoot(), get<0>(tupleItem), get<1>(tupleItem));
    if(lca)
      cout<<"For items "<< get<0>(tupleItem)<<" and " << get<1>(tupleItem) << " the lca is = "<<lca->m_data<<endl;
    else
      cout<<"Both items not found on the binary tree"<<endl;
  }
  return(0);
}
