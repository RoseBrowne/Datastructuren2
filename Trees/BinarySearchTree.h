//
//  BinarySearchTree.h
//  Trees
//
//  Created by Patrick Bergman on 07/10/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BinaryTree.h"

template <class T>
class BinarySearchTree : public BinaryTree<T> {
public:
    void insert(T newItem);
    bool contains(T searchItem);
    void rotateRight();
    void rotateLeft();
private:
    void rotateRight(TreeNode<T> * & leaf);
    void rotateLeft(TreeNode<T> * & leaf);
    void insert(T newItem, TreeNode<T> *leaf);
    bool contains(T searchItem, TreeNode<T> *leaf);
};

template <class T>
void BinarySearchTree<T>::insert(T newItem) {
    if(!contains(newItem)) {
        if(this->root == NULL)
        {
            this->root = new TreeNode<T>(newItem);
        } else {
            insert(newItem, this->root);
        }
    }
}

template <class T>
void BinarySearchTree<T>::insert(T newItem, TreeNode<T> *leaf) {
    if(newItem < leaf->getItem()) {
        if(leaf->leftLeaf != NULL) {
            insert(newItem, leaf->leftLeaf);
        } else {
            leaf->leftLeaf = new TreeNode<T>(newItem);
        }
    } else {
        if(leaf->rightLeaf != NULL) {
            insert(newItem, leaf->rightLeaf);
        } else {
            leaf->rightLeaf = new TreeNode<T>(newItem);
        }
    }
}

template <class T>
bool BinarySearchTree<T>::contains(T searchItem) {
    return contains(searchItem, this->root);
}

template <class T>
bool BinarySearchTree<T>::contains(T searchItem, TreeNode<T> *leaf) {
    if(leaf != NULL) {
        if(searchItem == leaf->getItem()) {
            return true;
        }
        if(searchItem < leaf->getItem()) {
            return contains(searchItem, leaf->leftLeaf);
        }
        if(searchItem > leaf->getItem()) {
            return contains(searchItem, leaf->rightLeaf);
        }
    }
    return false;
}

template <class T>
void BinarySearchTree<T>::rotateRight() {
    rotateRight(this->root);
}

template <class T>
void BinarySearchTree<T>::rotateRight(TreeNode<T> * & leaf) {
    TreeNode<T> *oldLeaf = leaf;
    leaf = leaf->leftLeaf;
    oldLeaf->leftLeaf = leaf->rightLeaf;
    leaf->rightLeaf = oldLeaf;
}

template <class T>
void BinarySearchTree<T>::rotateLeft() {
    rotateLeft(this->root);
}

template <class T>
void BinarySearchTree<T>::rotateLeft(TreeNode<T> * & leaf) {
    TreeNode<T> *oldLeaf = leaf;
    leaf = leaf->rightLeaf;
    oldLeaf->rightLeaf = leaf->leftLeaf;
    leaf->leftLeaf = oldLeaf;
}

#endif /* BinarySearchTree_h */