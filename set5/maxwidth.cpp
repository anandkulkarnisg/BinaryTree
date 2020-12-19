#include<algorithm>
#include<climits>
#include<iostream>
#include<string>
#include<utility>
#include<vector>

#include<BinaryTree.h>

using namespace std;

void getMaxWidthInternal(const BinaryTreeNode<int>* node, long& leftWidth, long& rightWidth, const long currLevel)
{
  if(!node)
    return;
  getMaxWidthInternal(node->m_leftChild, leftWidth, rightWidth, currLevel+1);
  getMaxWidthInternal(node->m_rightChild, leftWidth, rightWidth,currLevel-1);
  if(currLevel>leftWidth)
    leftWidth=currLevel;
  if(currLevel<rightWidth)
    rightWidth=currLevel;
}

long getMaxWidth(const BinaryTreeNode<int>* node)
{
  long leftWidth=0, rightWidth=0;
  getMaxWidthInternal(node, leftWidth, rightWidth, 0);
  return(leftWidth+abs(rightWidth));
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{1,2,3,99,4,5,99},{1,2,99,3,99,99,99},{1,99,2,99,99,99,3}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase, 99);
    cout<<"The maximum width is = "<<getMaxWidth(tree.getRoot())<<endl;
  }
  return(0);
}
