//
//  AVLTree.h
//  Trees
//
//  Created by Patrick Bergman on 14/10/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTree.h"
#include "AVLNode.h"

template <class T>
class AVLTree : public BinarySearchTree<T> {
public:
    int hieght(AVLNode<T> *newItem);
private:
    
};

#endif /* AVLTree_h */
