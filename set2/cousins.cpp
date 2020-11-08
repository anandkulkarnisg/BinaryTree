#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<sstream>
#include<BinaryTree.h>

using namespace std;

void areCousinsInternal(const BinaryTreeNode<int>* node, const int& item1, const int& item2, tuple<const int*, const int*>& addressPair, tuple<long, long>& levelPair,size_t currentLevel)
{
  if(!node)
    return;
  if((node->m_leftChild && node->m_leftChild->m_data==item1) || (node->m_rightChild && node->m_rightChild->m_data==item1))
  {
    get<0>(addressPair)=&node->m_data;
    get<0>(levelPair)=currentLevel+1;
  }
  if((node->m_leftChild && node->m_leftChild->m_data==item2) || (node->m_rightChild && node->m_rightChild->m_data==item2))
  {
    get<1>(addressPair)=&node->m_data;
    get<1>(levelPair)=currentLevel+1;
  }
  areCousinsInternal(node->m_leftChild, item1, item2, addressPair, levelPair, 1+currentLevel);
  areCousinsInternal(node->m_rightChild, item1, item2, addressPair, levelPair, 1+currentLevel);
}

bool areCousins(const BinaryTreeNode<int>* node, const int& item1, const int& item2)
{
  tuple<const int*, const int*> addressPair=make_tuple<const int*, const int*>(&node->m_data,&node->m_data);
  tuple<long, long> levelPair=make_tuple<long, long>(-1, -1);
  areCousinsInternal(node, item1, item2, addressPair, levelPair, 0);
  if(get<0>(addressPair)==&node->m_data||get<1>(addressPair)==&node->m_data)
    return(false);
  if(get<0>(levelPair)==-1||get<1>(levelPair)==-1)
    return(false);
  if((get<0>(addressPair)!=get<1>(addressPair)) && (get<0>(levelPair)==get<1>(levelPair)))
    return(true);
  return(false);
}

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7};
  BinaryTree<int> tree;
  tree.createFromArray(vec);

  // Check if two nodes given are cousins. Two nodes are cousins of each other if they are at same level and have different parents. 
  // Nodes are supplied by value and assume that all nodes have distinct values.
  vector<tuple<int, int>> testCases={make_tuple<int, int>(4, 5), make_tuple<int, int>(5, 6), make_tuple<int, int>(5, 7), make_tuple<int, int>(4, 6), make_tuple<int, int>(2, 6)};
  for(const auto& testCase : testCases)
  {
    bool solution=areCousins(tree.getRoot(), get<0>(testCase), get<1>(testCase));
    cout<<"cousin status of "<<get<0>(testCase) << " and " <<get<1>(testCase)<< " is = "<<solution<<endl;
  }

  // Another slightly complex test.
  BinaryTree<int> tree2;
  vector<int> vec2={1,2,3,4,99,99,5,6,99,99,99,99,99,99,7};
  tree2.createFromArray(vec2, 99);
  cout<<"cousin status of 6 and 7 is = "<<areCousins(tree2.getRoot(), 6, 7)<<endl;
  return(0);
}
