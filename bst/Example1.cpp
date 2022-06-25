#include<iostream>
#include<string>
#include<BinaryTree.h>
#include<BinarySearchTree.h>

using namespace std;

// Key point to observe.BinarySearchTree is not good when input numbers to be inserted are random and come in sorted order.
// The tree falls into degenerate state like a linkedList of height imbalanced state sooner or later without a rebalancing
// policy.Note how the third array perfectly fits the arrival items on BST which is also height balanced.

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,3},{4,2,1,3,6,5,7},{}};
  BinarySearchTree<int> bstTree(false);
  for(const auto& testCase : testCases){
    for(const auto& item : testCase)
      bstTree.insertItem(item);
    bstTree.doInOrderTraversal();
    cout<<"size="<<bstTree.size()<<", "<<"height="<<bstTree.height()<<", heightBalancedStatus="<<bstTree.isHeightBalanced()<<endl;
    cout<<"search status for 4="<<bstTree.searchItem(4).first<<endl;
    bstTree.resetBST();
  }
  return(0); 
}
