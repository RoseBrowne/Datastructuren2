/**
* TreeNode: The constructor for the nodes of binary trees, 
*	binary search trees and splay trees.
* @author Patrick Bergman (s1553097)
* @author Rose Browne (s1652834)
* @file TreeNode.h
* @date 01-11-2015
*
**/
#ifndef TreeNode_h
#define TreeNode_h

/* Every node in a tree consists of an element with the information in
that node, a pointer to it's right child and a pointer to it's left child.*/
template <class T>
class TreeNode {
private:
    T item;
public:
    TreeNode(T newItem);
    TreeNode *rightLeaf;
    TreeNode *leftLeaf;
    T getItem();
};

/* When a node is created it doesn't have children yet. Therefor the 
pointers to it's right and left child are left NULL upon initialization. */
template <class T>
TreeNode<T>::TreeNode(T newItem) {
    item = newItem;
    rightLeaf = NULL;
    leftLeaf = NULL;
}

/* This function is used to retrieve the information in a certain node, 
since item is declared private. */
template <class T>
T TreeNode<T>::getItem() {
    return item;
}

#endif /* TreeNode_h */
