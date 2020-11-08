#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={1, 2, 3, 4, 5}; 
  BinaryTree<int> tree;
  tree.createFromArray(vec); // This simply creates binary tree by assigning the items in level wise traversal from left to right.

  // This binary tree is height balanced.
  cout << tree.isHeightBalanced() << endl;

  vector<int> vec2={1, 2, 3, 4, 99, 99, 99, 5};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec2, 99); // drop 99 and make it null item.
  
  // This binary tree is not height balanced.
  cout << tree2.isHeightBalanced() << endl;
 
  return(0); 
}
