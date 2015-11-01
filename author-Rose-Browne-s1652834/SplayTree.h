/**
*
* @author Rose Browne (s1652834)
*
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

template <class T>
void SplayTree<T>::insert(T info){
	if(!this->contains(info)){
		TreeNode<T> *p = this->root;
		TreeNode<T> *prev = 0;
		while(p != 0){
			prev = p;
			if(info < p->getValue()){
				p = p->left;
				path.push('l');
			}
			else{
				p = p->right;
				path.push('r');
			}
		}
		if(this->root == 0){
			this->root = new TreeNode<T>(info);
		}
		else if(info < prev->getValue()){
			prev->left = new TreeNode<T>(info);
			splay(prev, prev->left);
		}
		else{
			prev->right = new TreeNode<T>(info);
			splay(prev, prev->right);
		}
	}
}

template <class T>
void SplayTree<T>::splay(TreeNode<T> *parent, TreeNode<T> *child){
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
			rotateLeft(this->root->left);
			rotateRight(this->root);
		}
		else if(reeks == "rl"){
			rotateRight(this->root->right);
			rotateLeft(this->root);
		}
	}
}

template <class T>
void SplayTree<T>::rotateRight(TreeNode<T> * & node){
  TreeNode<T> *oldNode = node;
  node = node->left;
  oldNode->left = node->right;
  node->right = oldNode;
}

template <class T>
void SplayTree<T>::rotateLeft(TreeNode<T> * & node){
  TreeNode<T> *oldNode = node;
  node = node->right;
  oldNode->right = node->left;
  node->left = oldNode;
}

#endif 
