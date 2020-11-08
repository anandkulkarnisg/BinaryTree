#include<iostream>
#include<iostream>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={4,3,5,1,99,99,6,0,99,99,99,99,99,99,7};
  BinaryTree<int> bt;
  bt.createFromArray(vec, 99);
  BinaryTree<int> copyTree(bt);
  
  // Check if they are the same. They should be.
  cout<<(bt==copyTree)<<endl;

  // Attempt a serialized tree load, clone and comparison check.
  bt.serialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example12.gz");
  
  // deserialize into a new tree.
  BinaryTree<int> bt2;
  bt2.deserialize("/home/anand/bitbucket/programming/dsalgo/binarytree/library/examples/Example12.gz");

  // Check if they are same.  
  cout<<(bt==bt2)<<endl;

  // Last test would be to compare two binary tree of different types.
  vector<int> vec2={4,3,5,1,99,99,6,0,99,99,99,99,99,99,8};
  BinaryTree<int> bt3;
  bt3.createFromArray(vec2, 99); 

  // Check if this and bt are same. They are not [ 7 vs 8 last item differ ].
  cout<<(bt==bt3)<<endl; 

  return(0);
}
