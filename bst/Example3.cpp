#include<iostream>
#include<string>
#include<BinarySearchTree.h>

using namespace std;

// Test deleteItem facility in the BST.
int main(int argc, char* argv[])
{
  BinarySearchTree<int> bstTree(false);
  vector<vector<int>> testCases={{15,10,20,8,12,18,25}};
  for(const auto& testCase : testCases){
    for(const auto& item : testCase)
      bstTree.insertItem(item);
    bstTree.doInOrderTraversal();
  }
  for(const auto& deleteItem : {8, 18, 12, 25, 10, 20, 15}){
    cout<<"After deletion of item="<<deleteItem<<endl;
    bstTree.deleteItem(deleteItem);
    bstTree.doInOrderTraversal();
  }
  cout<<"Demo of the deletion of a node with single child"<<endl;
  bstTree.reset();
  for(const auto& item : {15,10,20,8,12,18,25,16,19,30}){
    bstTree.insertItem(item); 
  }
  bstTree.doInOrderTraversal();
  cout<<"Aiming to delete the node = 25"<<endl;
  bstTree.deleteItem(25);
  cout<<"After the deletion"<<endl;
  bstTree.doInOrderTraversal();
  return(0);
}
