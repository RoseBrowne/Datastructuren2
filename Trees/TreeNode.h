//
//  TreeNode.h
//  Trees
//
//  Created by Patrick Bergman on 07/10/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

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

template <class T>
TreeNode<T>::TreeNode(T newItem) {
    item = newItem;
    rightLeaf = NULL;
    leftLeaf = NULL;
}

template <class T>
T TreeNode<T>::getItem() {
    return item;
}

#endif /* TreeNode_h */
