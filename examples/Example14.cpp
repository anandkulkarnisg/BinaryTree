#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={4,3,5,1,99,99,6,0,99,99,99,99,99,99,7}; 
  BinaryTree<int> tree;
  
  // Create the array.
  tree.createFromArray(vec, 99);  
  tree.doInOrderTraversal();
  vector<int> results;
  results.reserve(tree.size());

  // Collect the traversal in an array.
  tree.doInOrderTraversal(&results);
  for(const auto& iter : results)
    cout<<iter<<", ";
  cout<<'\n';

  return(0);
}
