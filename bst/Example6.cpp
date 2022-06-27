#include<iostream>
#include<BinarySearchTree.h>

using namespace std;

// Test deleteItem facility in the BST.
int main(int argc, char* argv[])
{
  BinarySearchTree<int> bstTree(false);
  for(const auto& item : {15,10,20,8,12,18,16,19,30})
    bstTree.insertItem(item); 
  bstTree.doInOrderTraversal();
  cout<<"case 1 : Attempting to delete the leaf node = 30"<<endl;
  bstTree.deleteItem(30);
  bstTree.doInOrderTraversal();
  cout<<"case 2 : Attempting to delete the node with single child = 20"<<endl;
  bstTree.deleteItem(20);
  bstTree.doInOrderTraversal();
  cout<<"Case 3 : Attempting to delete root node = 15"<<endl;
  bstTree.deleteItem(15);
  bstTree.doInOrderTraversal();
  return(0);
}
