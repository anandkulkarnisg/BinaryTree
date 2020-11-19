#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void findFloorCeilBSTInternal(const BinaryTreeNode<int>* node, const int& searchItem, tuple<int, int>& resultPair)
{
  if(!node)
    return;

  if(isLeaf(node))
  {
    if(node->m_data>searchItem)
      get<1>(resultPair)=node->m_data;
    if(node->m_data<searchItem)
      get<0>(resultPair)=node->m_data;
    return;
  }

  if(node->m_data==searchItem)
  {
    get<0>(resultPair)=get<1>(resultPair)=node->m_data;
    return;
  }
  else if(node->m_leftChild&&node->m_leftChild->m_data<searchItem && node->m_data>searchItem)
  {
    get<0>(resultPair)=node->m_leftChild->m_data;
    get<1>(resultPair)=node->m_data;
    return;
  }
  else if(node->m_rightChild&&node->m_rightChild->m_data>searchItem && node->m_data<searchItem)
  {
    get<0>(resultPair)=node->m_data;
    get<1>(resultPair)=node->m_rightChild->m_data;
    return;
  }

  if(searchItem<node->m_data)
    findFloorCeilBSTInternal(node->m_leftChild, searchItem, resultPair);
  else
    findFloorCeilBSTInternal(node->m_rightChild, searchItem, resultPair);
}

tuple<int, int> findFloorCeilBST(const BinaryTreeNode<int>* node, const int& searchItem)
{
  tuple<int, int> resultPair=make_tuple<int, int>(-INT_MAX, INT_MAX);
  findFloorCeilBSTInternal(node, searchItem, resultPair);
  return(resultPair);
}

// Expected Algorithmic complexity : O(n)  : Traversal one time.
// Expected auxillary memory complexity : O(1).

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{8,4,12,2,6,10,14}};
  vector<int> searchItems={11,1,6,15};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    for(const auto& searchItem : searchItems)
    {
      tuple<int, int> resultPair=findFloorCeilBST(tree.getRoot(), searchItem);
      cout<<"The Floor and Ceil results for key = "<<searchItem<<" are "<<get<0>(resultPair)<<" and "<<get<1>(resultPair)<<" respectively."<<endl;
    }
  }
  return(0);
}
