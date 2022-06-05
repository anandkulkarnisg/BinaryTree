#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<BinaryTree.h>

using namespace std;

// The algorithmic complexity is : O(n) and space complexity is O(1) i.e does not take any extra memory based on input size.
void doDescendingBstTraversal(const BinaryTreeNode<int>* node){
   if(!node)
       return;
   // The recursive traversal is rightChild->parent->left [ which is exact opposite of in order traversal.
    doDescendingBstTraversal(node->m_rightChild);
    cout << node->m_data << ", ";
    doDescendingBstTraversal(node->m_leftChild);
}

int main(int argc, char* argv[]){
    unique_ptr<BinaryTree<int>> uniqueBstPtr(new BinaryTree<int>({4, 2, 6, 1, 3, 5, 7}));
    uniqueBstPtr->doInOrderTraversal();
    cout<<"Reverse InOrder Traversal : ";
    doDescendingBstTraversal(uniqueBstPtr->getRoot());
    // Verify that the tree is indeed BST.
    cout << "\nisBST() status = " << uniqueBstPtr->isBST() << endl;
    cout<<'\n';
    return(0);
}