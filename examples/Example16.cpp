#include<iostream>
#include<string>
#include<vector>
#include<BinaryTree.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7};

  // Create a Binary Tree in strict mode [ which is default ].
  cout<<"Example1 : "<<endl;
  BinaryTree<int> bTree;
  bTree.createFromArray(vec);
  cout << "File is saved down to : " <<bTree.serialize("Example16.gz")<<endl;
  return(0);
}

