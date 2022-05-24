#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  // A sample test of initializing a binary tree using levelmap.It can help construct any shape/type of binary tree.
  vector<size_t> idxList={0,1,2,3,6,7,14};
  vector<int> valList={3,4,5,6,9,11,13};
  BinaryTree<int> tree1;
  tree1.createFromLevelArray(idxList, valList);
  tree1.doInOrderTraversal();
  cout<<"tree1 degenerate status="<<tree1.isDegenerate()<<endl;

  // Build a degenerate binary tree here.
  vector<size_t> idxList2={0,1,3};
  vector<int> valList2={1,3,5};
  BinaryTree<int> tree2;
  tree2.createFromLevelArray(idxList2, valList2);
  tree2.doInOrderTraversal();
  cout<<"tree2 degenerate status="<<tree2.isDegenerate()<<endl;
  return(0); 
}