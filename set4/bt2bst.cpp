#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

void inOrderTraversalAssign(BinaryTreeNode<int>* node, const vector<int>& store, size_t& startIdx)
{
  if(!node)
    return;
  inOrderTraversalAssign(node->m_leftChild, store, startIdx);
  node->m_data=store[startIdx];
  ++startIdx;
  inOrderTraversalAssign(node->m_rightChild, store, startIdx);
}

void convertBinaryTreeToBST(BinaryTree<int>& tree)
{
  BinaryTreeNode<int>* node=tree.getRoot();
  if(!node)
    return;
  vector<int> store;
  store.reserve(tree.size());
  tree.doInOrderTraversal(&store);
  sort(store.begin(), store.end());
  size_t startIdx=0;
  inOrderTraversalAssign(node, store, startIdx);
}

// Expected Algorithmic Complexity : O(nlog(n)) , Auxillary Memory Complexity : O(n) [ array of same size as BST ].
// Is a better aux memory optimization possible.

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{10,5,8,2,20,99,99},{10,5,22,2,8,18,20},{7,5,9,10,6,8,4}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    convertBinaryTreeToBST(tree);
    cout<<"After : "<<endl;
    tree.doInOrderTraversal();
  }
  return(0);
}
