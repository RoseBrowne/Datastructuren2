/**
* BinaryTree: A Tree in which new nodes can be inserted, deleted, searched for,
* saved to a .dot file and be displayed in the 3 different orders.
* @author Patrick Bergman (s1553097)
* @author Rose Browne (s1652834)
* @file BinaryTree.h
* @date 01-11-2015
*
**/

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

/* If the root is equal to NULL the item to be inserted is the first 
item of the tree and therefor automatically the root. */
template <class T>
void BinaryTree<T>::insert(T newItem) {
    if(root == NULL)
    {
        root = new TreeNode<T>(newItem);
    } else {
        insert(newItem, root);
    }
}

/* In case the item to be inserted is not the root of the tree, we need
to find an available free space for the node. */
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

/* The noded we're looking for is compared to each node in the tree
starting with the root untill we find one that equals it. */
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

/* Here the pre order ordening is printed to the screen. */
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

/* Here the in order ordening is printed to the screen. */
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

/* Here the post order ordening is printed to the screen. */
template <class T>
void BinaryTree<T>::showPostOrder(TreeNode<T> *leaf) {
    if(leaf != NULL) {
        showPreOrder(leaf->leftLeaf);
        showPreOrder(leaf->rightLeaf);
        std::cout << leaf->getItem() << " ";
    }
}

/* Here the current tree is saved to a .dot file. First code to begin
and end an .dot file and the root are written to a .dot file
 (in case it doesn't equal NULL). In between the function is called again
 with extra parameters to print all the children of the root. */
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

/* Here the children of the root are written to the .dot file. Within 
the function a nodeCounter is kept to know which node is connected to
which node. */
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

/* Here the tree is destroyed. */
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
