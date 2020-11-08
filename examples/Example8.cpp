#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec;
  size_t reserveSize=100000;
  vec.reserve(reserveSize);
  for(unsigned int i=0;i<reserveSize;++i)
    vec.emplace_back(i);
  BinaryTree<int> tree;
  tree.createBSTFromSortedArray(vec);
  const char* fileName="/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example8.gz";
  tree.serialize(fileName);

  // Create a new binary tree from deserialization.
  BinaryTree<int> tree2;
  tree2.deserialize(fileName);
  cout<<"BST status = "<<tree2.isBST()<<" and size = "<<tree2.size()<<endl;

  // Try a simple non BST tree with some null override.
  vector<int> vec2={1, 2, 3, 4, 99, 99, 99, 5};
  BinaryTree<int> tree3;
  tree3.createFromArray(vec2, 99);
  tree3.serialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example8a.gz");

  // Stick this into a new tree and see if works fine.
  BinaryTree<int> tree4;
  tree4.deserialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example8a.gz");
  cout<<"BST status = "<<tree4.isBST()<<" and size = "<<tree4.size()<<endl;
  tree4.doInOrderTraversal(); 
  return(0);
}
