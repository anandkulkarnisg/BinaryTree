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

int main(int argc, char* argv[]){
  vector<vector<int>> testCases={{10, 99, 20, 99, 99, 99, 30}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases){
    tree.createFromArray(testCase, 99);    
    tree.doInOrderTraversal();
    cout<<"Before height = "<<tree.height()<<endl;
    cout<<"After RRrotation"<<endl;
    doAvlRightRightRotation(tree);
    tree.clearPropertyCache();
    tree.doInOrderTraversal();
    cout<<"After height = "<<tree.height()<<endl;
  }
  return(0);
}
