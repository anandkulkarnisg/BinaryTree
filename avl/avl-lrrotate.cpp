#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

void doAvlLeftLeftRotation(BinaryTree<int>& tree){
  // First identify the binaryTree root as node.
  BinaryTreeNode<int>* node=tree.getRoot();
  // Step1 : Identify the immediate left child and left grand child nodes.
  BinaryTreeNode<int>* leftChild = node->m_leftChild;
  // Step2 : Make the node the rightChild of the current leftChild.
  leftChild->m_rightChild = node;
  // Disconnect the node from its current left and right children.
  node->m_leftChild=node->m_rightChild=nullptr;
  // Make the leftChild node the root.
  tree.setRoot(leftChild);
}

void doAvlLeftRightRotation(BinaryTree<int>& tree){
  // First identify the binaryTree root as node.
  BinaryTreeNode<int>* node=tree.getRoot();
  // Step1: Convert the tree first to left left imbalance position.We first take the right child of node->m_leftChild and make it rightChild of same parent.
  node->m_leftChild->m_rightChild->m_leftChild=node->m_leftChild;
  node->m_leftChild=node->m_leftChild->m_rightChild;
  // Reset the circular relationship and make the below node leaf.
  BinaryTreeNode<int>* makeLeafNode=node->m_leftChild->m_leftChild;
  makeLeafNode->m_leftChild=makeLeafNode->m_rightChild=nullptr;
  // Now pass this tree as input to the LL rotate algorithm.
  doAvlLeftLeftRotation(tree);  
}

int main(int argc, char* argv[]){
  vector<vector<int>> testCases={{30, 10, 99, 99, 20, 99, 99}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases){
    tree.createFromArray(testCase, 99);    
    tree.doInOrderTraversal();
    cout<<"Before height = "<<tree.height()<<endl;
    cout<<"After LR double rotation"<<endl;
    doAvlLeftRightRotation(tree);
    tree.clearPropertyCache();
    tree.doInOrderTraversal();
    cout<<"After height = "<<tree.height()<<endl;
  }
  return(0);
}
