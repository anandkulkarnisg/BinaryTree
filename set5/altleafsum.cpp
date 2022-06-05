#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<BinaryTree.h>

using namespace std;

enum includeType { leftChild, rightChild };

bool isLeaf(const BinaryTreeNode<int>* node){
    return(!node->m_leftChild&&!node->m_rightChild);
}

void getAlternateLeafSumInternal(const BinaryTreeNode<int>* node, long& sum, bool& includeExcludeFlag){
    if(!node)
        return;
    if(isLeaf(node)){
        if(includeExcludeFlag){
            sum+=node->m_data;
            includeExcludeFlag=false;   // Makes sure you skip the next one.
        }
        else
            includeExcludeFlag=true;    // This ensures that next leaf is picked up again.
    }
    if(node->m_leftChild){
        getAlternateLeafSumInternal(node->m_leftChild, sum, includeExcludeFlag);
    }
    if(node->m_rightChild){
        getAlternateLeafSumInternal(node->m_rightChild, sum, includeExcludeFlag);
    }
}

// Algorithmic Complexity : O(n) , Auxiliary Memory complexity : O(1).
long getAlternateLeafSum(const BinaryTreeNode<int>* node, const includeType currIncludeType){
  long sum=0;
  bool includeExcludeFlag=false;
  if(currIncludeType==includeType::leftChild)
      includeExcludeFlag=true;
  getAlternateLeafSumInternal(node, sum, includeExcludeFlag);
  return(sum);
}

int main(int argc, char* argv[]){
    unique_ptr<BinaryTree<int>> uniqueBstPtr(new BinaryTree<int>({1, 2, 3, 4, 5, 6, 7}));
    cout<<"The alternative leaf sum = " << getAlternateLeafSum(uniqueBstPtr->getRoot(), includeType::rightChild) << endl;
    cout<<"The alternative leaf sum = " << getAlternateLeafSum(uniqueBstPtr->getRoot(), includeType::leftChild) << endl;
    return(0);
}