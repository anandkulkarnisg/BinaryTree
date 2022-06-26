#include<iostream>
#include<string>
#include<BinarySearchTree.h>

using namespace std;

// Test searchItem facility in the BST.
int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,4,5,7}};
  BinarySearchTree<int> bstTree(false);
  for(const auto& testCase : testCases){
    for(const auto& item : testCase)
      bstTree.insertItem(item);
    bstTree.doInOrderTraversal();
    cout<<"Starting to search for the items"<<endl;
    vector<int> searchSpace={-1,1,2,3,4,5,6,7,10};
    for(const auto& item: searchSpace){
      cout<<"The search status for item = "<<item<<" is = "<<bstTree.searchItem(item).first<<endl;
    }
  }
  return(0); 
}
