#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

// This function checks if the node1 is contained with in another binary tree with starting point of node2 [ which means node1->m_data==node2->m_data has been verified ].
// This is not same as subtree problem. Read the code carefully.
bool checkContains(const BinaryTreeNode<int>* node1, const BinaryTreeNode<int>* node2, long& iterations)
{
  if(iterations<0)
    return(true);
  if(!node1)
    return(true);

  bool returnStatus1=true, returnStatus2=false, returnStatus3=true;
  if(node1->m_leftChild)
  {
    if(!node2->m_leftChild)
      return(false);
    else
      returnStatus1=checkContains(node1->m_leftChild, node2->m_leftChild, iterations);
  }
  //cout<<"Attempting to compare "<<node1->m_data<<" and "<<node2->m_data<<" with iterations left = "<<iterations<<endl;
  if(node1->m_data==node2->m_data)
  {
    returnStatus2=true;
    --iterations;
  }

  if(node1->m_rightChild)
  {
    if(!node2->m_rightChild)
      return(false);
    else
      returnStatus3=checkContains(node1->m_rightChild, node2->m_rightChild, iterations);
  }
  return(returnStatus1&&returnStatus2&&returnStatus3);
}

// Iterate tree starting at node1 in in order traversal and if node matches node of tree2 then start doing contains checking further.
bool containsInternal(const BinaryTreeNode<int>* node1, const BinaryTreeNode<int>* node2, long size)
{
  if(!node1||!node2)
    return(false);
  bool result1=containsInternal(node1->m_leftChild, node2, size);
  bool result2=false;
  if(node1->m_data==node2->m_data)
    result2=checkContains(node2, node1, size);  // Note : node2 is passed first argument since checkContains traverses structure of BT of first argument.size is size of tree of node2.
  bool result3=containsInternal(node1->m_rightChild, node2, size);
  return(result1||result2||result3);
}

// Checks if the tree2 is a part of the tree1.
bool contains(BinaryTree<int>& tree1, BinaryTree<int>& tree2)
{
  size_t size1=tree1.size();
  size_t size2=tree2.size();
  if(!size2)
    return(true); // null tree is always contained in another tree. 
  if(size2>size1)
    return(false);  // The tree2 can not be inside tree1 if it is bigger in size.
  return(containsInternal(tree1.getRoot(), tree2.getRoot(), size2));
}

BinaryTreeNode<int>* createExample()
{
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
  root->m_leftChild=new BinaryTreeNode<int>(2);
  root->m_rightChild=new BinaryTreeNode<int>(5);
  root->m_leftChild->m_rightChild=new BinaryTreeNode<int>(3);
  root->m_rightChild->m_leftChild=new BinaryTreeNode<int>(6);
  root->m_leftChild->m_rightChild->m_leftChild=new BinaryTreeNode<int>(4);
  root->m_rightChild->m_leftChild->m_rightChild=new BinaryTreeNode<int>(7);
  root->m_rightChild->m_leftChild->m_rightChild->m_leftChild=new BinaryTreeNode<int>(8);
  root->m_rightChild->m_leftChild->m_rightChild->m_rightChild=new BinaryTreeNode<int>(9);
  root->m_rightChild->m_leftChild->m_rightChild->m_leftChild->m_leftChild=new BinaryTreeNode<int>(10);
  root->m_rightChild->m_leftChild->m_rightChild->m_leftChild->m_rightChild=new BinaryTreeNode<int>(11);
  root->m_rightChild->m_leftChild->m_rightChild->m_rightChild->m_leftChild=new BinaryTreeNode<int>(12);
  root->m_rightChild->m_leftChild->m_rightChild->m_rightChild->m_rightChild=new BinaryTreeNode<int>(13);
  root->m_rightChild->m_leftChild->m_rightChild->m_rightChild->m_leftChild->m_rightChild=new BinaryTreeNode<int>(14); 
  return(root);
}

int main(int argc, char* argv[])
{
  vector<int> vec={7,99,9,99,99,12,99,99,99,99,99,99,14,99,99};
  BinaryTreeNode<int>* root=createExample();
  BinaryTree<int> tree1(root, true, true);  // A strict binaryTree which clones a tree from root node and then cleansup the tree pointed by root.
  BinaryTree<int> tree2;
  tree2.createFromArray(vec,99);

  // Check if tree2 is contained within tree1 [ this is not same as subtree problem ].
  bool result=contains(tree1, tree2);
  cout<<"result="<<result<<endl;
  return(0);
}
