#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

BinaryTree<int> createBinaryTree()
{
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);
  return(tree); 
}

void printInOrderTraversal(BinaryTree<int> tree)
{
  tree.doInOrderTraversal();
}

int main(int argc, char* argv[])
{
  // Example1 : The below triggers move copy constructor to save down costly copy.
  cout<<"Example1 : "<<endl;
  printInOrderTraversal(createBinaryTree());

  // Example2 : create an object and move it over to called function leaving current object empty.
  cout<<"Example2 : "<<endl;
  vector<int> vec={1,2,3}, vec2={4,5,6};
  BinaryTree<int> tree;
  tree.createFromArray(vec);
  cout<<"before : ";
  tree.doInOrderTraversal();
  cout<<"After move call to function : ";
  printInOrderTraversal(std::move(tree));
  cout<<"After move complete, the tree should be empty here : ";
  tree.doInOrderTraversal();

  // Example3 : The below demonstrates the use of move assignment operator.
  cout<<"Example3 : "<<endl;
  BinaryTree<int> tree2, tree3;
  tree2.createFromArray(vec);
  tree3.createFromArray(vec2);
  tree2=std::move(tree3);
  
  cout<<"Attempt to print the original tree which was moved, tree3."<<endl;
  tree3.doInOrderTraversal(); 
  cout<<"The below tree should print vec2 which is 4,5 and 6."<<endl; 
  tree2.doInOrderTraversal();


  // Example4 : Attempt a self move assignment. Should handle it properly.
  cout<<"Example4 : "<<endl;
  BinaryTree<int> tree4;
  tree4.createFromArray(vec);
  cout<<"before : "<<endl;
  tree4.doInOrderTraversal();
  tree4=std::move(tree4);
  cout<<"After the self move assignment attempt tree4 should remain the same."<<endl;
  tree4.doInOrderTraversal();
 
  // Exit gracefully.
  return(0);
}
