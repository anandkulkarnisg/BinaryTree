#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  // First Example We test if a binaryTree in relaxed mode will print properly. I.e can change underneath tree.
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{8,9,10,11,12,13,14}};
  BinaryTree<int> relaxedTree(testCases[0],false);
  cout<<"relaxedTree demonstration :"<<'\n';
  relaxedTree.doInOrderTraversal();
  relaxedTree.createFromArray(testCases[1]);
  relaxedTree.doInOrderTraversal();

  // Second Example we test if a binaryTree is immutable as expected in strict mode [ which is default].
  cout<<"strict tree demonstration : "<<'\n';
  BinaryTree<int> tree(testCases[0]);  
  tree.doInOrderTraversal();
  tree.createFromArray(testCases[1]); 
  tree.doInOrderTraversal();
  return(0); 
}
