#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  // Step 1 : Create a binary tree [ BST ] as below.
  vector<int> vec={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  BinaryTree<int> tree;
  tree.createBSTFromSortedArray(vec);
  tree.serialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example10.gz");
 
  // Step 2 : load the tree from disk. 
  BinaryTree<int> tree2;
  tree2.deserialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example10.gz");
  tree2.doInOrderTraversal();

  return(0);
}
