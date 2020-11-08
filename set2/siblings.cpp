#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

bool areSiblings(const BinaryTreeNode<int>* node, const int& child1, const int& child2)
{
  if(!node)
    return(false);

  if(node->m_leftChild&&node->m_leftChild->m_data==child1&&node->m_rightChild&&node->m_rightChild->m_data==child2)
    return(true);

  return(areSiblings(node->m_leftChild, child1, child2)||areSiblings(node->m_rightChild, child1, child2));
}

int main(int argc, char* argv[])
{
  vector<tuple<int, int>> testCases={make_tuple<int,int>(2,3),make_tuple<int, int>(4,5),make_tuple<int, int>(6,7),make_tuple<int,int>(3,4),make_tuple<int,int>(5,7)};
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);

  // Check if two given values are siblings or not. Here value of node is supplied and assumed that each node has unique value.
  bool solution;
  for(const auto& testCase : testCases)
  {
    solution=areSiblings(tree.getRoot(), get<0>(testCase), get<1>(testCase));
    cout<<"sibling status for items "<<get<0>(testCase)<<" and "<<get<1>(testCase)<<" is ="<<solution<<endl;
  }
  return(0);
}
