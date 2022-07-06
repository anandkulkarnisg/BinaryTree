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
    cout<<"Inserting the item = "<<insertItem<<endl;
    avlTree.insertItem(insertItem);
  }
  cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  for(const auto& deleteItem : {28, 5, 10, 27, 30, 20, 25}){
    cout<<"The root of the AVL BST tree is = "<<avlTree.getRoot()->m_data<<endl;
    cout<<"Attempting to delete the item = "<<deleteItem<<endl;
    pair<bool,BinaryTreeNode<int>*> searchStatusPair=avlTree.searchItem(deleteItem);
    cout<<"The search status for = "<<deleteItem<<" is = "<<searchStatusPair.first<<endl;
    bool deleteStatus=avlTree.deleteItem(deleteItem);
    cout<<"The deletion status = "<<deleteStatus<<endl;
    if(avlTree.getRoot()){
      cout<<"The new root after deletion is = "<<avlTree.getRoot()->m_data<<endl;
      cout<<"The inorder traversal is : "<<endl;
      displayBalanceFactorsInOrder(avlTree.getRoot());
    }
    else
      cout<<"The tree is empty/null."<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
  }
  return(0);
}
