//
//  AVLNode.h
//  Trees
//
//  Created by Patrick Bergman on 14/10/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#include "TreeNode.h"

#ifndef AVLNode_h
#define AVLNode_h

template <class T>
class AVLNode : public TreeNode {
private:
    unsigned int height;
public:
    int getHeight();
    void setHeight(unsigned int height);
};

template <class T>
int AVLNode<T>::getHeight() {
    return height;
}

template <class T>
void AVLNode<T>::setHeight(unsigned int height) {
    height = height;
}

#endif /* AVLNode_h */
