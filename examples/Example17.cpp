#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  // Test which data types are supported.
  cout<<BinaryTree<int>::getSupportedTypes()<<endl;

  // Test a sample binary tree with characters in it.
  vector<char> vec= {'a','b','c','d','e','f','g','h','i'};
  BinaryTree<char> tree;
  tree.createBSTFromSortedArray(vec);
  tree.doInOrderTraversal();
  cout<<"BST status = "<<tree.isBST()<<endl;
  
  // Attempt to serialize the tree.
  const char* path="/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example17.gz";
  tree.serialize(path);

  // Read the same tree back into memory and compare if it is same as tree above.
  BinaryTree<char> tree2;
  tree2.deserialize(path);
  tree2.doInOrderTraversal();
 
  // Are the trees same ?
  cout<<"Are they same status = "<<(tree==tree2)<<endl;
  return(0);
}
