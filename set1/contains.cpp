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

int main(int argc, char* argv[])
{
  /* Example1 is below.
      3
    / \
   4   5
  / \
 1   2
    /
   0
 Given tree t:
   4 
  / \
 1   2
 */

  vector<vector<int>> vec={{3,4,5,1,2,99,99,99,99,0,99,99,99,99,99},{4,1,2}};
  BinaryTree<int> tree1, tree2;
  tree1.createFromArray(vec[0], 99);
  tree2.createFromArray(vec[1]);

  // Check if tree2 is contained within tree1 [ this is not same as subtree problem ].
  bool result=contains(tree1, tree2);
  cout<<"result="<<result<<endl;

  // Example2 is below.
  /* Tree1 :
         1
	     /   \
            2     3
           / \    / \
          4   5   6   7
        / \          / \
       8   9        10

    Tree2 :
             3
              \
               7
              /
             10
  */
  vector<vector<int>> vec2={{1,2,3,4,5,6,7,8,9,99,99,99,99,10,99},{3,99,7,99,99,10,99}};
  BinaryTree<int> tree3, tree4;
  tree3.createFromArray(vec2[0], 99);
  tree4.createFromArray(vec2[1], 99);
  cout<<"result="<<contains(tree3, tree4)<<endl;
  return(0);
}
