#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7}, vec2={8,9,10,11,12,13,15};

  // Create a Binary Tree in strict mode [ which is default ].
  cout<<"Example1 : "<<endl;
  BinaryTree<int> bTree;
  bTree.createFromArray(vec);
  bTree.doInOrderTraversal();

  // Attempt to Alter the tree.Should fail since the default mode is strict=true.
  bTree.createFromArray(vec2);
  bTree.doInOrderTraversal();

  // Create a BinaryTree with relaxed mode. [ where its structure can be altered multiple times ].
  cout<<"Example2 : "<<endl;
  BinaryTree<int> bTreeRelaxed(false);
  bTreeRelaxed.createFromArray(vec);
  bTreeRelaxed.doInOrderTraversal();

  // Attempt to alter the tree should work. The old tree will be cleaned up and new one will be assigned.
  bTreeRelaxed.createFromArray(vec2);
  bTreeRelaxed.doInOrderTraversal();

  // Create a binaryTree in strict mode. Attempt a trigger of move assignment. should fail to change the tree.
  cout<<"Example3 : "<<endl;
  BinaryTree<int> bTreeMoveTest;
  bTreeMoveTest.createFromArray(vec);
  bTreeMoveTest.doInOrderTraversal();
  
  // Attempt a move of some other object into bTreeMoveTest.Should fail.
  bTreeMoveTest=std::move(bTreeRelaxed);
  bTreeMoveTest.doInOrderTraversal();

  // Attempt to set bTreeRelaxed by moving the bTreeMoveTest. Should work.
  cout<<"Example4 : "<<endl;
  bTreeRelaxed=std::move(bTreeMoveTest);
  bTreeRelaxed.doInOrderTraversal();
  bTreeMoveTest.doInOrderTraversal();

  return(0);
}
