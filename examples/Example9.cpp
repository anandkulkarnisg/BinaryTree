#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={4,3,5,1,99,99,6,0,99,99,99,99,99,99,7};
  BinaryTree<int> tree2;
  tree2.createFromArray(vec, 99);
  tree2.doInOrderTraversal();
  tree2.serialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example9.gz");

  BinaryTree<int> tree3;
  tree3.deserialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example9.gz");
  tree3.doInOrderTraversal();

  return(0);
}
