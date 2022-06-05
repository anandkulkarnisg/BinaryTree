#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<BinaryTree.h>

using namespace std;
void doZigZagTraversal(const BinaryTreeNode<int>* node, const bool& direction)
{
  if(!node)
    return;

  stack<const BinaryTreeNode<int>*> stack1, stack2;
  bool currDirection=direction;
  stack1.push(node);

  while(!stack1.empty())
  {
    const BinaryTreeNode<int>* curr=stack1.top();
    stack1.pop(); 
    if(curr)
    {
      cout<<curr->m_data<<", ";
      if(currDirection)
      {
        if(curr->m_leftChild)
          stack2.push(curr->m_leftChild);
        if(curr->m_rightChild)
          stack2.push(curr->m_rightChild);
      }
      else
      {
        if(curr->m_rightChild)
          stack2.push(curr->m_rightChild);
        if(curr->m_leftChild)
          stack2.push(curr->m_leftChild);
      }
    }

    if(stack1.empty())
    {
      // switch direction.
      currDirection=!currDirection;
      // Swap the stacks.
      swap(stack1, stack2);
      // newline to separate levels.
      cout<<'\n';
    }
  }
}

int main(int argc, char* argv[])
{
  vector<int> vec={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  BinaryTree<int> tree(false);
  tree.createFromArray(vec);
  // Let us do a zig zag traversal. Its a level order traversal where order of traversal is changing direction at every level.
  cout<<"zigzag traversal is below"<<'\n';
  doZigZagTraversal(tree.getRoot(), true);
  return(0);
}
