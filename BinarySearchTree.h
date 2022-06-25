#include<iostream>
#include<string>
#include<BinaryTree.h>

using namespace std;

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

template<typename T> class BinarySearchTree : public BinaryTree<T>
{
  private:
    void searchItemInternal(BinaryTreeNode<T>*, const T&, pair<bool, BinaryTreeNode<T>*>&);

  public:
    BinarySearchTree(const bool&);
    void insertItem(const T&);
    pair<bool, BinaryTreeNode<T>*> searchItem(const T&);
    void deleteItem(const T&);
    void resetBST();
};

#endif
