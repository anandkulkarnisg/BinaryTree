#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

enum class bstRebalancePolicy { size, height, predecessor, successor };

template<typename T> class BinarySearchTree : public BinaryTree<T>
{
  private:
    void searchItemInternal(BinaryTreeNode<T>*, const T&, pair<bool, BinaryTreeNode<T>*>&);
    BinaryTreeNode<T>* findParentInternal(const T&);
    void rebalancePredecessor(BinaryTreeNode<T>*);
    void rebalanceSuccessor(BinaryTreeNode<T>*);
    bstRebalancePolicy m_rebalancePolicy=bstRebalancePolicy::successor;

  protected:
    BinaryTreeNode<T>* findSuccessor(const BinaryTreeNode<T>*);
    BinaryTreeNode<T>* findPredecessor(const BinaryTreeNode<T>*);

  public:
    BinarySearchTree(const bool&);
    pair<bool, BinaryTreeNode<T>*> insertItem(const T&);
    pair<bool, BinaryTreeNode<T>*> searchItem(const T&);
    bool deleteItem(const T&);
    void setBSTRebalancePolicy(const bstRebalancePolicy&);
    bstRebalancePolicy getBSTRebalancePolicy();
};

#endif
