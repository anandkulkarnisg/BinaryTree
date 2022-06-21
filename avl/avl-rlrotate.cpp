#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

void doAvlRightRightRotation(BinaryTree<int>& tree){
  // First identify the binaryTree root as node.
  BinaryTreeNode<int>* node=tree.getRoot();
  // Step1 : Make the node the leftChild of its current rightChild.
  BinaryTreeNode<int>* rightChild=node->m_rightChild;
  rightChild->m_leftChild=node;
  // Step2 : cleanup the node childen.
  node->m_leftChild=node->m_rightChild=nullptr;
  // Step3 : Set the rightChild as the root.
  tree.setRoot(rightChild);
}

void doAvlRightLeftRotation(BinaryTree<int>& tree){
  // First identify the binaryTree root as node.
  BinaryTreeNode<int>* node=tree.getRoot();
  // We first convert the tree to right right imbalance as below. 
  node->m_rightChild->m_leftChild->m_rightChild=node->m_rightChild;
  node->m_rightChild=node->m_rightChild->m_leftChild;
  // Break the circular reference and make the below node leaf.
  BinaryTreeNode<int>* makeLeafNode=node->m_rightChild->m_rightChild;
  makeLeafNode->m_leftChild=makeLeafNode->m_rightChild=nullptr;
  // Now pass this tree as input to the LL rotate algorithm.
  doAvlRightRightRotation(tree);  
}

int main(int argc, char* argv[]){
  vector<vector<int>> testCases={{10, 99, 30, 99, 99, 20, 99}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases){
    tree.createFromArray(testCase, 99);
    tree.doInOrderTraversal();
    cout<<"Before height = "<<tree.height()<<endl;
    cout<<"After RL double rotation"<<endl;
    doAvlRightLeftRotation(tree);
    tree.clearPropertyCache();
    tree.doInOrderTraversal();
    cout<<"After height = "<<tree.height()<<endl;
  }
  return(0);
}
