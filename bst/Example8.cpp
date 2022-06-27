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
  cout<<"Case 1 : Aiming for a root node deletion(15) with successor policy"<<endl;
  bstTree.deleteItem(15);
  bstTree.doInOrderTraversal();
  cout<<"After the root removal new root is = "<<bstTree.getRoot()->m_data<<endl;
  cout<<"Case 2 : Aiming for a root node deletion(16) with predecessor policy"<<endl;
  bstTree.setBSTRebalancePolicy(bstRebalancePolicy::predecessor);
  bstTree.deleteItem(16);
  bstTree.doInOrderTraversal();
  cout<<"After the root removal new root is = "<<bstTree.getRoot()->m_data<<endl;
  cout<<"Case 3 : Aiming for a root node deletion(12) with height policy"<<endl;
  bstTree.setBSTRebalancePolicy(bstRebalancePolicy::height);
  bstTree.deleteItem(12);
  bstTree.doInOrderTraversal();
  cout<<"After the root removal new root is = "<<bstTree.getRoot()->m_data<<endl;
  cout<<"Case 4 : Aiming for a root node deletion(18) with size policy"<<endl;
  bstTree.setBSTRebalancePolicy(bstRebalancePolicy::size);
  bstTree.deleteItem(18);
  bstTree.doInOrderTraversal();
  cout<<"After the root removal new root is = "<<bstTree.getRoot()->m_data<<endl;
  return(0);
}
