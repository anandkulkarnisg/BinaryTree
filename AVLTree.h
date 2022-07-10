#include<iostream>
#include<string>
#include<BinarySearchTree.h>

using namespace std;

#ifndef AVLTree_H
#define AVLTree_H

template<typename T> class AVLTree : public BinarySearchTree<T>
{
  private:
    void reCalcBalanceFactors();
    long reCalcBalanceFactorsInternal(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* doRRRotation(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* doLLRotation(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* doLRRotation(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* doRLRotation(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* runAVLRotations(BinaryTreeNode<T>*);
    BinaryTreeNode<T>* insertAVLItemInternal(BinaryTreeNode<T>*,const T&,BinaryTreeNode<T>**);
    BinaryTreeNode<T>* deleteItemInternal(BinaryTreeNode<T>*, const T&);
    BinaryTreeNode<T>* runAVLDeleteRotations(BinaryTreeNode<T>*);
    bool in(const long&, const vector<long>&);

  public:
    AVLTree(const bool&);
    pair<bool, BinaryTreeNode<T>*> insertItem(const T&);
    pair<bool, BinaryTreeNode<T>*> searchItem(const T&);
    bool deleteItem(const T&);
};

#endif

