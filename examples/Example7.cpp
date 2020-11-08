#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={1, 2, 3}; 
  BinaryTree<int> tree;
  tree.createBSTFromSortedArray(vec);

  // Test if this is a BST. It is. 
  cout << tree.isBST() << endl;

  vector<int> vec2={3, 2, 5, 1, 4};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec2);

  // Test if this is a BST. It is not.
  cout << tree2.isBST() << endl;  

  vector<int> vec3={2, 3, 1};
  BinaryTree<int> tree3;
  tree3.createFromArray(vec3);

  // Test if the below is a BST. It is. [ descending ].
  cout << tree3.isBST() << endl;

  vector<int> vec4={4, 2, 1, 1, 3};
  BinaryTree<int> tree4;
  tree4.createFromArray(vec4);
  
  // Test if the below is BST. it is not [ duplicate 1 key ].
  cout << tree4.isBST() << endl;

  vector<int> vec5={4, 6, 2, 7, 5, 3, 1};
  BinaryTree<int> tree5;
  tree5.createFromArray(vec5);
  
  // Test if this is BST. It is [ descending array ].
  cout << tree5.isBST() << endl; 

  vector<int> vec6={4, 2, 6, 99, 3, 5, 99};
  BinaryTree<int> tree6;
  tree6.createFromArray(vec6, 99);
  
  // Test if the below is a BST. It is although it is non complete tree.
  cout << tree6.isBST() << endl; 

  vector<int> vec7={2, 3, 1, 99, 99, 3, 99};
  BinaryTree<int> tree7;
  tree7.createFromArray(vec7, 99);

  // Test if this is a BST. It is not since the descending tree has a duplicate key 3.
  cout << tree7.isBST() << endl;
  return(0); 
}
