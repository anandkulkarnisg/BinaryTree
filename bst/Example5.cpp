#include<iostream>
#include<string>
#include<BinarySearchTree.h>

using namespace std;

// Test deleteItem facility in the BST.
int main(int argc, char* argv[])
{
  BinarySearchTree<int> bstTree(false);
  cout<<"Demo of the deletion of a node with single child"<<endl;
  for(const auto& item : {15,10,20,8,12,18,16,19,30})
    bstTree.insertItem(item); 
  bstTree.doInOrderTraversal();
  cout<<"Attempting to delete the node = 15"<<endl; 
  bstTree.deleteItem(15); 
  bstTree.doInOrderTraversal();
  return(0);
}
