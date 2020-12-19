#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

bool isHalfNode(const BinaryTreeNode<int>* node)
{
  return((node->m_leftChild&&!node->m_rightChild)||(!node->m_leftChild&&node->m_rightChild));
}

// Deletion : post order traversal : Algorthmic Complexity : O(n), Auxillary Memory Complexity : O(1).
BinaryTreeNode<int>* removeHalfNodesInternal(BinaryTreeNode<int>* node)
{
  if(!node)
    return(nullptr);
  node->m_leftChild=removeHalfNodesInternal(node->m_leftChild);
  node->m_rightChild=removeHalfNodesInternal(node->m_rightChild);
  if(!isHalfNode(node))
    return(node);
  BinaryTreeNode<int>* retNode=(node->m_leftChild) ? node->m_leftChild : node->m_rightChild;
  //cout<<"deleting the node = "<<node->m_data<<endl;
  delete(node);
  return(retNode);
}

void removeHalfNodes(BinaryTree<int>& tree)
{
  tree.setRoot(removeHalfNodesInternal(tree.getRoot()));
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{0, 1, 2, 3, 99, 4, 99, 5, 99, 99, 99, 6, 7, 99, 99},{1,2,3,4,5,6,7},{1,2,99,3,99,99,99}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"Before : "<<endl;
    tree.doInOrderTraversal();
    removeHalfNodes(tree);
    cout<<"After : "<<endl;
    tree.doInOrderTraversal(); 
  }
  return(0);
}
