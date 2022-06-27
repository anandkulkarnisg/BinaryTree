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
  cout<<"Case 3 : Attempting to delete root node = 15"<<endl;
  bstTree.deleteItem(15);
  bstTree.doInOrderTraversal();
  cout<<"the root node now is ="<<bstTree.getRoot()->m_data<<endl; 
  // Now switch the policy recreate the same bstTree and use predecessor policy for deletion.
  bstTree.reset();  // Clean the tree.
  bstTree.setBSTRebalancePolicy(bstRebalancePolicy::predecessor);
  cout<<"After switching policy to predecessor"<<endl;
  for(const auto& item : {15,10,20,8,12,18,16,19,30})
    bstTree.insertItem(item);
  bstTree.doInOrderTraversal();
  cout<<"Case 3 : Attempting to delete root node = 15"<<endl;
  bstTree.deleteItem(15);
  bstTree.doInOrderTraversal();
  cout<<"the root node now is ="<<bstTree.getRoot()->m_data<<endl;
  return(0);
}
