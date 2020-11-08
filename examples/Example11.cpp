#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  // Basic Initialization.
  vector<int> vec={4,3,99,2,99,99,99,1,99,99,99,99,99,99,99,0,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99};
  const char* fileName="/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example11.gz";

  // Step 1 : Create a binary tree [ BST ] as below.
  BinaryTree<int> tree;
  tree.createFromArray(vec,99); // treat 99 as null item.
  cout<<tree.isBST()<<","<<tree.height()<<","<<tree.isHeightBalanced()<<endl;
  tree.serialize(fileName);

  // Step 2: Attempt to serialize and deserialize this tree.
  BinaryTree<int> copyTree;
  copyTree.deserialize(fileName);
  cout<<copyTree.isBST()<<","<<copyTree.height()<<","<<copyTree.isHeightBalanced()<<endl; 
  return(0);
}
