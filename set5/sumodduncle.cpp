#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<BinaryTree.h>

using namespace std;
using namespace boost;

// Solution 1.
void findSumImpl(const BinaryTreeNode<int>* node, std::vector<std::pair<const BinaryTreeNode<int>*, bool>>& arr, const int& idx, long& sum, const bool childType){
  if(!node)
    return;
  arr[idx]=make_pair<const BinaryTreeNode<int>*, bool>(dynamic_cast<const BinaryTreeNode<int>*>(node), static_cast<bool>(childType));
  if(idx>1&&node->m_data%2==1){
    const BinaryTreeNode<int>* grandParentNode=arr[idx-2].first;
    bool parentType=arr[idx-1].second;
    if(parentType){
     if(grandParentNode->m_rightChild&&grandParentNode->m_rightChild->m_data%2==1){
       //cout<<"node val="<<node->m_data<<" and uncle is = "<<grandParentNode->m_rightChild->m_data<<endl;
       sum+=node->m_data;
      }
    }else{
      if(grandParentNode->m_leftChild&&grandParentNode->m_leftChild->m_data%2==1){
        //cout<<"node val="<<node->m_data<<" and uncle is = "<<grandParentNode->m_leftChild->m_data<<endl;
        sum+=node->m_data;
      }
    }
  }
  findSumImpl(node->m_leftChild, arr, idx+1, sum, true);
  findSumImpl(node->m_rightChild, arr, idx+1, sum, false);
}

long findSumWhereUncleAndNodeAreOdd(const unique_ptr<BinaryTree<int>>& treeRef){
  long sum=0;
  size_t height=treeRef.get()->height();
  std::vector<std::pair<const BinaryTreeNode<int>* ,bool>> arr;
  arr.reserve(height+1);
  findSumImpl(treeRef.get()->getRoot(), arr, 0, sum, false);
  return(sum);
}

bool matches(const BinaryTreeNode<int>* node){
  return(node&&node->m_data%2==1);
}

void findSumImpl2(const BinaryTreeNode<int>* node, const BinaryTreeNode<int>* parentNode, const size_t currentLevel, long & sum, const bool isLeftOrRight){
  if(!node)
    return;
  if(currentLevel>0&&parentNode){
    BinaryTreeNode<int>* uncleNode=(isLeftOrRight)?parentNode->m_rightChild:parentNode->m_leftChild;
    if(matches(node->m_leftChild)&&matches(uncleNode))
      sum+=node->m_leftChild->m_data;
    if(matches(node->m_rightChild)&&matches(uncleNode))
      sum+=node->m_rightChild->m_data;
  }
  // Now invoke further recursive calls.
  findSumImpl2(node->m_leftChild, node, currentLevel+1, sum, true);
  findSumImpl2(node->m_rightChild, node, currentLevel+1, sum, false);
}

// Solution 2 : The auxillary complexity is now O(1) as we dont use array of size h or is it really (since stack eventually holds all recursive call variables in until it unwinds )?
long findSumOddUncle(const unique_ptr<BinaryTree<int>>& treeRef){
  long sum=0;
  findSumImpl2(treeRef.get()->getRoot(), nullptr, 0, sum, false);
  return(sum);
}

// Question : Identify the total sum of all such nodes where the node is odd and its uncle node is also odd.
// uncle node is the cousin node of the parent node, if uncle node does not exist for a given node, then dont consider the node.
// Below is a simple depiction of uncle node [rp] for node [x].
//                               g
//                           lp    rp
//                          x  y  a   b

// Algorithmic complexity : O(n).
// Auxillary Memory complexity : O(h) = O(log(n)) [ array size is proportional to binary tree height, a balanced tree will have O(log(n)) height ].
// Q:Is it possible to make auxillary memory O(1) to keep track of only parent and grand parent for each node ?

int main(int argc, char* argv[]){
  unique_ptr<BinaryTree<int>> uniqueBstPtr(new BinaryTree<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}));
  //unique_ptr<BinaryTree<int>> uniqueBstPtr(new BinaryTree<int>({1, 2, 3, 4, 5, 6, 7}));
  long sum=findSumWhereUncleAndNodeAreOdd(uniqueBstPtr);
  long sumAlt=findSumOddUncle(uniqueBstPtr);
  cout<<"sum="<<sum<<endl;
  cout<<"sumAlt="<<sumAlt<<endl;
  return(0);
}
