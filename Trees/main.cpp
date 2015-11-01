//
//  main.cpp
//  Trees
//
//  Created by Patrick Bergman on 30/09/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "SplayTree.h"

int main() {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(20);
    tree.insert(9);
    tree.insert(18);
    tree.insert(22);
    //tree.showPreOrder();
    std::cout << std::endl;
    tree.saveAsDot("text.txt");
    //tree.rotateLeft();
    tree.saveAsDot("right.txt");
    
    return 0;
}
