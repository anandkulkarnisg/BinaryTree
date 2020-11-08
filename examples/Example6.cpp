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

  // This binary tree is not a degenerate tree. 
  cout << tree.isDegenerate() << endl;

  vector<int> vec2={1, 2, 99, 3, 99, 99, 99, 4, 99};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec2, 99); // drop 99 and make it null item.
 
  // This tree is degenerate since it is a linked list in disguise. 
  cout << tree2.isDegenerate() << endl;
 
  return(0); 
}
