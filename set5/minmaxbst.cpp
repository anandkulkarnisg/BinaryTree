#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

enum bstType {min, max};
int isLeaf(const BinaryTreeNode<int>* node){
  return(!node->m_leftChild&&!node->m_rightChild);
}

// Identify the min and max values in a binary tree. Complexity is O(log(n,2)) and Auxilary memory complexity is O(1).
template<typename T> T getMinMaxBST(const BinaryTreeNode<T>* node,const bstType& minMaxType){
  if(!node)
    return(0);
  if(isLeaf(node))
    return(node->m_data);
  if(minMaxType==bstType::min)
    return(getMinMaxBST(node->m_leftChild, minMaxType));
  return(getMinMaxBST(node->m_rightChild, minMaxType));
}

int main(int argc, char* argv[]){
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases){
    tree.createBSTFromSortedArray(testCase);
    cout << "Min item = " << getMinMaxBST(tree.getRoot(), bstType::min) << endl; 
    cout<< "Max item = " << getMinMaxBST(tree.getRoot(), bstType::max)<< endl;
  }
  return(0);
}
