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

  // This tree is indeed full since every node has either 0 or 2 children.
  cout << tree.isFull() << endl;

  vector<int> vec2={1, 2, 3, 4, 5, 99, 7};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec2, 99); // drop 99 and make it null item.

  // This tree is not full since 99 is null hence node 3 does not have a left child but does have a right child.
  cout << tree2.isFull() << endl;
 
  return(0); 
}
