#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<char> vec={'a','b','c','d','f','i','l','y','z'};
  BinaryTree<char> charTree;
  charTree.createBSTFromSortedArray(vec);
  charTree.doInOrderTraversal();
  cout<<"isBST Status="<<charTree.isBST()<<endl;
  cout<<"Supported types for BinaryTree<T> are : "<<charTree.getSupportedTypes()<<endl;
  return(0); 
}
