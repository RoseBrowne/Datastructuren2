/**
* BinarySearchTree: The constructor and operations on a binary search tree.
* Same as BinaryTree, but now all the nodes have to be unique and the tree
* knows a specifik ordering.
* @author Patrick Bergman (s1553097)
* @author Rose Browne (s1652834)
* @file BinarySearchTree.h
* @date 01-11-2015
*
**/
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

/* Here the insert function has been expanded, because know a node 
can be inserted either as a left or right child from it's parent depending
on the value of the node the be inserted and it's parent. If the node 
has a smaller value than it's parent it will be inserted left of the
parent. Otherwise it will be inserted right of the parent. */
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

/* The contains() function has also been expanded here, since know a
node can be located either left or right from the previous node.
First the root is checked, than depending on whether the value of the node
smaller or greater is than it's parent the searching continues left or
right. */
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

/* Here a singular right rotation is performed on the leaf that gets 
passed along. A copy is kept in oldLeaf to change leaf and connect them
again at the end. */
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

/* Here a singular left roation is performed. */
template <class T>
void BinarySearchTree<T>::rotateLeft(TreeNode<T> * & leaf) {
    TreeNode<T> *oldLeaf = leaf;
    leaf = leaf->rightLeaf;
    oldLeaf->rightLeaf = leaf->leftLeaf;
    leaf->leftLeaf = oldLeaf;
}

#endif /* BinarySearchTree_h */
