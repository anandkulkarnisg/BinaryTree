#include<iostream>
#include<AVLTree.h>

using namespace std;

void displayBalanceFactorsInOrder(const BinaryTreeNode<int>* node)
{
  if(!node)
    return;
  if(node->m_leftChild)
    displayBalanceFactorsInOrder(node->m_leftChild);
  cout<<"Item val="<<node->m_data<<", "<<" and node bf = "<<node->m_balanceFactor<<endl;
  if(node->m_rightChild)
    displayBalanceFactorsInOrder(node->m_rightChild);
}

int main(int argc, char* argv[])
{
  AVLTree<int> avlTree(false);
  if(!avlTree.getRoot())
    cout<<"The tree is null"<<endl;
  for(const auto& insertItem : {10, 20, 30, 25, 28, 27, 5}){
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"Inserting the item = "<<insertItem<<endl;
    avlTree.insertItem(insertItem);
    displayBalanceFactorsInOrder(avlTree.getRoot());
  }
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  cout<<"The root node of AVL Tree = " <<avlTree.getRoot()->m_data<<endl;
  cout<<"The root node balance factor of AVL Tree = " <<avlTree.getRoot()->m_balanceFactor<<endl;
  cout<<"The size of tree is = "<<avlTree.size()<<endl;
  cout<<"The height of the tree is = "<<avlTree.height()<<endl;
  displayBalanceFactorsInOrder(avlTree.getRoot());
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  return(0);
}
