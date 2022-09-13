#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<BinaryTree.h>

using namespace std;
using namespace boost;

void findSumImpl(const BinaryTreeNode<int>* node, int arr[], const int& idx, long& sum){
  if(!node)
    return;
  arr[idx]=node->m_data;
  if(idx>1&&node->m_data%2==1&&arr[idx-2]%2==1){
    //cout<<"node val="<<node->m_data<<" and grand parent is = "<<arr[idx-2]<<endl;
    sum+=node->m_data;
  } 
  findSumImpl(node->m_leftChild, arr, idx+1, sum);
  findSumImpl(node->m_rightChild, arr, idx+1, sum); 
}

long findSumwhereGrandParentChildrenOdd(const unique_ptr<BinaryTree<int>>& treeRef){
  long sum=0;
  size_t height=treeRef.get()->height();
  int arr[height+1];
  findSumImpl(treeRef.get()->getRoot(), arr, 0, sum);
  return(sum);
}

// Alternate solution using current node and its parent node in parameter list.Perhaps O(1) or atleast better than O(h) memory usage.
void findSumImpl2(const BinaryTreeNode<int>* node, const BinaryTreeNode<int>* parentNode, long& sum){
  if(!node)
    return;
  if(parentNode){
    if(node->m_leftChild&&node->m_leftChild->m_data%2==1&&parentNode->m_data%2==1)
      sum+=node->m_leftChild->m_data;
    if(node->m_rightChild&&node->m_rightChild->m_data%2==1&&parentNode->m_data%2==1)
      sum+=node->m_rightChild->m_data;
  }
  // Do further recursive calls.
  findSumImpl2(node->m_leftChild, node, sum);
  findSumImpl2(node->m_rightChild, node, sum);
}

long findSumAlternateMethod(const unique_ptr<BinaryTree<int>>& treeRef){
  long sum=0;
  findSumImpl2(treeRef.get()->getRoot(), nullptr, sum);
  return(sum);
}

// Question : Identify the total sum of all such nodes where the node is odd and its grand parent is also odd.
// grand parent is the parent node of the parent of current node.If grand parent doesnt exist, then dont consider the node.

// Algorithmic complexity : O(n).
// Auxillary Memory complexity : O(h) = O(log(n)) [ array size is proportional to binary tree height, a balanced tree will have O(log(n)) height ].
// Q:Is it possible to make auxillary memory O(1) to keep track of only parent and grand parent for each node ?

int main(int argc, char* argv[]){
  unique_ptr<BinaryTree<int>> uniqueBstPtr(new BinaryTree<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}));
  long sum=findSumwhereGrandParentChildrenOdd(uniqueBstPtr);
  long altSum=findSumAlternateMethod(uniqueBstPtr);  
  cout<<"sum="<<sum<<" and altSum="<<altSum<<endl;
  return(0);
}
