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

int main(int argc, char* argv[]){
  vector<vector<int>> testCases={{30, 20, 99, 10, 99, 99, 99}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases){
    tree.createFromArray(testCase, 99);    
    tree.doInOrderTraversal();
    cout<<"Before height = "<<tree.height()<<endl;
    cout<<"After LLrotation"<<endl;
    doAvlLeftLeftRotation(tree);
    tree.clearPropertyCache();
    tree.doInOrderTraversal();
    cout<<"After height = "<<tree.height()<<endl;
  }
  return(0);
}
