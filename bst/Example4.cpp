#include<iostream>
#include<string>
#include<BinarySearchTree.h>

using namespace std;

// Test deleteItem facility in the BST.
int main(int argc, char* argv[])
{
  BinarySearchTree<int> bstTree(false);
  cout<<"Demo of the deletion of a node with single child"<<endl;
  for(const auto& item : {15,10,20,8,12,18,25,16,19,30,31}){
    bstTree.insertItem(item); 
  }
  bstTree.doInOrderTraversal();
  cout<<"Aiming to delete the node = 25"<<endl;
  bstTree.deleteItem(25);
  cout<<"After the deletion"<<endl;
  bstTree.doInOrderTraversal();
  cout<<"Aiming to delete the leaf node = 31"<<endl;
  bstTree.deleteItem(31);
  cout<<"After the deletion"<<endl;
  bstTree.doInOrderTraversal();
  return(0);
}
