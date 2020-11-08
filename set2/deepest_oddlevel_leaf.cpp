#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<BinaryTree.h>

using namespace std;

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void deepestOddLevelLeaf(const BinaryTreeNode<int>* node, int& solution, size_t currentLevel, size_t& maxLevel)
{
  if(!node)
    return;
  if(currentLevel%2==1&&isLeaf(node)&&currentLevel>maxLevel)
    solution=node->m_data;
  deepestOddLevelLeaf(node->m_leftChild, solution, 1+currentLevel, maxLevel);
  deepestOddLevelLeaf(node->m_rightChild, solution, 1+currentLevel, maxLevel);
}

int getDeepestOddLevelLeaf(const BinaryTreeNode<int>* node)
{
  int solution=-1;
  size_t maxLevel=1;
  deepestOddLevelLeaf(node, solution, 1, maxLevel);
  return(solution);
}

int main(int argc, char* argv[])
{
  /* Example Tree : below.
       1
     /   \
    2     3
  /      /  \
 4      5    6
        \     \
         7     8
        /       \
       9         10
                 /
                11 
  */

  vector<int> vec={1,2,3,4,99,5,6,99,99,99,99,99,7,99,8,99,99,99,99,99,99,99,99,99,99,9,99,99,99,99,10,99, 99,
                   99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,11,99
                  };
  BinaryTree<int> tree;
  tree.createFromArray(vec, 99);
  tree.doInOrderTraversal();
  
  // Identify the deepest odd level leaf in the Tree.If multiple then return the first one.
  // Given assumptions : Consider that level starts with 1. Depth of a leaf node is number of nodes on the path from root to leaf [including both leaf and root].
  int solution=getDeepestOddLevelLeaf(tree.getRoot());
  cout<<"deepest odd level leaf is = "<<solution<<endl;
  return(0);
}
