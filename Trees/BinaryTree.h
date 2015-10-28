//
//  BinaryTree.h
//  Trees
//
//  Created by Patrick Bergman on 30/09/15.
//  Copyright © 2015 Patrick Bergman. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <fstream>
#include "TreeNode.h"

template <class T>
class BinaryTree {
public:
    BinaryTree();
    void insert(T newItem);
    bool contains(T searchItem);
    void showPreOrder();
    void showInOrder();
    void showPostOrder();
    void saveAsDot(std::string fileName);
    ~BinaryTree();
protected:
    TreeNode<T> *root;
private:
    int nodeCounter;
    void insert(T newItem, TreeNode<T> *leaf);
    bool contains(T searchItem, TreeNode<T> *leaf);
    void showPreOrder(TreeNode<T> *leaf);
    void showInOrder(TreeNode<T> *leaf);
    void showPostOrder(TreeNode<T> *leaf);
    void saveAsDot(TreeNode<T> *leaf, int &parentNode, std::ofstream &file);
    void destroyTree(TreeNode<T> *leaf);
};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}

template <class T>
void BinaryTree<T>::insert(T newItem) {
    if(root == NULL)
    {
        root = new TreeNode<T>(newItem);
    } else {
        insert(newItem, root);
    }
}

template <class T>
void BinaryTree<T>::insert(T newItem, TreeNode<T> *leaf) {
    if(leaf->rightLeaf) {
        insert(newItem, leaf->rightLeaf);
    } else {
        leaf->rightLeaf = new TreeNode<T>(newItem);
    }
}

template <class T>
bool BinaryTree<T>::contains(T searchItem) {
    return contains(searchItem, root);
}

template <class T>
bool BinaryTree<T>::contains(T searchItem, TreeNode<T> *leaf) {
    if(leaf != NULL) {
        if(searchItem == leaf->getItem()) {
            return true;
        } else if(leaf->rightLeaf) {
            return contains(searchItem, leaf->rightLeaf);
        }
        return false;
    }
    return false;
}

template <class T>
void BinaryTree<T>::showPreOrder() {
    showPreOrder(root);
}

template <class T>
void BinaryTree<T>::showPreOrder(TreeNode<T> *leaf) {
    if(leaf != NULL) {
        std::cout << leaf->getItem() << " ";
        showPreOrder(leaf->leftLeaf);
        showPreOrder(leaf->rightLeaf);
    }
}

template <class T>
void BinaryTree<T>::showInOrder() {
    showInOrder(root);
}

template <class T>
void BinaryTree<T>::showInOrder(TreeNode<T> *leaf) {
    if(leaf != NULL) {
        showPreOrder(leaf->leftLeaf);
        std::cout << leaf->getItem() << " ";
        showPreOrder(leaf->rightLeaf);
    }
}

template <class T>
void BinaryTree<T>::showPostOrder() {
    showPostOrder(root);
}

template <class T>
void BinaryTree<T>::showPostOrder(TreeNode<T> *leaf) {
    if(leaf != NULL) {
        showPreOrder(leaf->leftLeaf);
        showPreOrder(leaf->rightLeaf);
        std::cout << leaf->getItem() << " ";
    }
}

template <class T>
void BinaryTree<T>::saveAsDot(std::string fileName) {
    if(root != NULL) {
        nodeCounter = 1;
        std::ofstream file;
        file.open(fileName.c_str(), std::ios::out);
        file << "digraph BinaryTree {" << std::endl;
        file << "  " << nodeCounter << " [label=\"" << root->getItem() << "\"]" << std::endl;
        int parentNode = 1;
        saveAsDot(root, parentNode, file);
        file << "}" << std::endl;
        file.close();
    } else {
        std::cout << "Er zijn nog geen knopen om uit te printen" << std::endl;
    }
}

template <class T>
void BinaryTree<T>::saveAsDot(TreeNode<T> *leaf, int &parentNode, std::ofstream &file) {
    if(leaf != NULL) {
        if(leaf->leftLeaf != NULL) {
            nodeCounter++;
            file << "  " << nodeCounter << " [label=\"";
            file << leaf->leftLeaf->getItem() << "\"]" << std::endl;
            file << "  " << parentNode << " -> " << nodeCounter << std::endl;
            int newLeftParentNode = nodeCounter;
            saveAsDot(leaf->leftLeaf, newLeftParentNode, file);
        }
        if(leaf->rightLeaf != NULL) {
            nodeCounter++;
            file << "  " << nodeCounter << " [label=\"";
            file << leaf->rightLeaf->getItem() << "\"]" << std::endl;
            file << "  " << parentNode << " -> " << nodeCounter << std::endl;
            int newRightParentNode = nodeCounter;
            saveAsDot(leaf->rightLeaf, newRightParentNode, file);
        }
    }
}

template <class T>
void BinaryTree<T>::destroyTree(TreeNode<T> *leaf) {
    if(leaf != NULL) {
        destroyTree(leaf->leftLeaf);
        destroyTree(leaf->rightLeaf);
        delete leaf;
    }
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    destroyTree(root);
}

#endif /* BinaryTree_h */
