#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

template<typename T> vector<T> getInOrderItems(BinaryTree<T>& tree)
{
  vector<T> results;
  results.reserve(tree.size());
  tree.doInOrderTraversal(&results);
  return(results);
}

int main(int argc, char* argv[])
{
  BinaryTree<int> relaxedTree({1,2,3,4,5,6,7},false);
  for(const auto& iter : getInOrderItems(relaxedTree))
    cout<<iter<<", ";
  cout<<'\n';
  return(0); 
}
