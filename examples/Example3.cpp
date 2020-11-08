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

  // Here we simply check the type of tree using examples. 
  cout << tree.isComplete() << endl;

  vector<int> vec2={1, 2, 3, 4, 5, 6, 7};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec2, 6); // drop 6 and make it null item.

  // This tree is not complete. Since 6 which is left child is null and that causes incomplete ness.
  cout << tree2.isComplete()<<endl;
 
  return(0); 
}
