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
  
  // Let us check first if the size, height is proper.
  cout << "size = " << tree.size() << endl;
  cout << "height = " << tree.height() << endl;

  // Check if the levels information is correct.
  cout << "levels = " << tree.levels() << endl;

  // Check if the traversals are proper.
  tree.doInOrderTraversal();    // This should be 4, 2, 5, 1, 3  
  tree.doPreOrderTraversal();   // This should be 2, 4, 5, 1, 3
  tree.doPostOrderTraversal();  // This should be 4, 5, 2, 3, 1

  // Check if the root item is proper.
  cout << "The root item is = " << tree.getRoot()->m_data << endl;
  return(0); 
}
