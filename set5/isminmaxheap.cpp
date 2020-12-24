#include<algorithm>
#include<climits>
#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<vector>
#include<stack>

#include<BinaryTree.h>

using namespace std;

enum class HeapType { min, max };

bool isLeaf(const BinaryTreeNode<int>* node)
{
  return(!node->m_leftChild&&!node->m_rightChild);
}

void isMinMaxHeapInternal(const BinaryTreeNode<int>* root, const HeapType& heapType, size_t& violations)
{
  if(!root)
    return;
  if(heapType==HeapType::min&&!isLeaf(root))
  {
    if(!((root->m_leftChild&&root->m_data<root->m_leftChild->m_data)&&(root->m_rightChild&&root->m_data<root->m_rightChild->m_data)))
    {
      ++violations;
      return;
    }
  }
  if(heapType==HeapType::max&&!isLeaf(root))
  {
    if(!((root->m_leftChild&&root->m_data>root->m_leftChild->m_data)&&(root->m_rightChild&&root->m_data>root->m_rightChild->m_data)))
    {
      ++violations;
      return;
    }
  }
  isMinMaxHeapInternal(root->m_leftChild, heapType, violations);
  isMinMaxHeapInternal(root->m_rightChild, heapType, violations);
}

bool isMinOrMaxHeap(const BinaryTreeNode<int>* root, const HeapType& heapType)
{
  size_t violations=0;
  isMinMaxHeapInternal(root, heapType, violations);
  return(violations==0);
}

int main(int argc, char* argv[])
{
  vector<vector<int>> testCases={{1,2,3,4,5,6,7},{7,6,5,4,3,2,1},{4,2,6,1,3,5,7}};
  BinaryTree<int> tree(false);
  for(const auto& testCase : testCases)
  {
    tree.createFromArray(testCase);
    tree.doInOrderTraversal();
    cout<<"For this tree minHeap Status = "<<isMinOrMaxHeap(tree.getRoot(), HeapType::min)<<endl;
    cout<<"For this tree maxHeap Status = "<<isMinOrMaxHeap(tree.getRoot(), HeapType::max)<<endl;
  }
  return(0);
}
