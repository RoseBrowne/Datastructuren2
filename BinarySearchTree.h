/**
*
* @author Rose Browne (s1652834)
*
**/

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <fstream>
#include <iostream>
#include "Tree.h"

template <class T>
class BinarySearchTree : public Tree<T>{
	public:
		void insert(T info);
		bool contains(T info);
		void rotateRight(TreeNode<T> *node);
		void rotateLeft(TreeNode<T> *node);
	private:
    void insert(T info, TreeNode<T> *node);
    void contains(T info, TreeNode<T> *node, bool &found);
};

template <class T>
void BinarySearchTree<T>::insert(T info){
	if(!contains(info)){
		TreeNode<T> *p = Tree<T>::root;
		TreeNode<T> *prev = 0;
		while(p != 0){
			prev = p;
			if(info < p->getValue()){
				p = p->left;
			}
			else{
				p = p->right;
			}
		}
		if(Tree<T>::root == 0){
			Tree<T>::root = new TreeNode<T>(info);
		}
		else if(info < prev->getValue()){
			prev->left = new TreeNode<T>(info);
		}
		else{
			prev->right = new TreeNode<T>(info);
		}
	}

}

template <class T>
void BinarySearchTree<T>::insert(T info, TreeNode<T> *node){

}

template <class T>
bool BinarySearchTree<T>::contains(T info){
		bool found = false;
		if(Tree<T>::root != NULL){
			if(Tree<T>::root->getValue() == info){
				found = true;
			}
			else{
				contains(info, Tree<T>::root->left, found);
				contains(info, Tree<T>::root->right, found);
			}
		}
		return found;
}

template <class T>
void BinarySearchTree<T>::contains(T info, TreeNode<T> *node, bool &found){
	if(node != NULL){
		if(node->getValue() == info){
			found = true;
		}
		else{
			contains(info, node->left, found);
			contains(info, node->right, found);
		}
	}
}

template <class T>
void BinarySearchTree::rotateRight(TreeNode<T> *node){
	TreeNode<T> hulpNode = node->left;
    node->left = node->left->right;
    hulpNode->right = node;
}
template <class T>
void BinarySearchTree::rotateLeft(TreeNode<T> *node){
	TreeNode<T> hulpNode = node->right;
    node->right = node->right->left;
    hulpNode->leftleft = node;
}
#endif 
