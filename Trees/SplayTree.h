/**
* SplayTree: performs the splay on a binary tree when new nodes are
* inserted to keep the tree balanced.
* @author Patrick Bergman (s1553097)
* @author Rose Browne (s1652834)
* @file SplayTree.h
* @date 01-11-2015
**/

#ifndef SplayTree_h
#define SplayTree_h
#include "BinarySearchTree.h"
#include <queue>

template <class T>
class SplayTree : public BinarySearchTree<T>{
	public:
		void insert(T info);
		std::queue<char> path;   
	private:
		void insert(T info, TreeNode<T> * & p);
		void splay(TreeNode<T> *parent, TreeNode<T> *child);
		void rotateRight(TreeNode<T> * & node);
		void rotateLeft(TreeNode<T> * & node);
};

/* After the insertion of a new node the binary tree gets splayed. */
template <class T>
void SplayTree<T>::insert(T info){
	if(!this->contains(info)){
		TreeNode<T> *p = this->root;
		TreeNode<T> *prev = 0;
		while(p != 0){
			prev = p;
			/* The place of a new node in the tree is saved in the queue "path".
			This is needed to know which splay must be performed, e.g. zig zig or zig zag. */
			if(info < p->getItem()){
				p = p->leftLeaf;
				path.push('l');
			}
			else{
				p = p->rightLeaf;
				path.push('r');
			}
		}
		if(this->root == 0){
			this->root = new TreeNode<T>(info);
		}
		else if(info < prev->getItem()){
			prev->leftLeaf = new TreeNode<T>(info);
			splay(prev, prev->leftLeaf);
		}
		else{
			prev->rightLeaf = new TreeNode<T>(info);
			splay(prev, prev->rightLeaf);
		}
	}
}

/* Here is determined which sequence of rotations is performed based
on the place of the node in the tree. */ 
template <class T>
void SplayTree<T>::splay(TreeNode<T> *parent, TreeNode<T> *child){
	/* Every possible sequence exists of maximum 2 combinations of 
	left "l" en right "r". Therefor the queue is split up in new 
	sequences of two. */
	while(child != this->root){
		std::string reeks = "";
		for(int i = 0; i < 2; i++){
			reeks += path.front();
			path.pop();
			if(path.empty()){
				i = 1;
			}
		}	
		if(reeks == "l"){
			rotateRight(this->root);
		}
		else if(reeks == "r"){
			rotateLeft(this->root);
		}
		else if(reeks == "ll"){
			rotateRight(this->root);
			rotateRight(this->root);
		}
		else if(reeks == "rr"){
			rotateLeft(this->root);
			rotateLeft(this->root);
		}
		else if(reeks == "lr"){
			rotateLeft(this->root->leftLeaf);
			rotateRight(this->root);
		}
		else if(reeks == "rl"){
			rotateRight(this->root->rightLeaf);
			rotateLeft(this->root);
		}
	}
}

/* Here an singular right rotation is performed. */
template <class T>
void SplayTree<T>::rotateRight(TreeNode<T> * & node){
  TreeNode<T> *oldNode = node;
  node = node->leftLeaf;
  oldNode->leftLeaf = node->rightLeaf;
  node->rightLeaf = oldNode;
}

/* Here an singular left rotation is performed. */
template <class T>
void SplayTree<T>::rotateLeft(TreeNode<T> * & node){
  TreeNode<T> *oldNode = node;
  node = node->rightLeaf;
  oldNode->rightLeaf = node->leftLeaf;
  node->leftLeaf = oldNode;
}

#endif 
