/**
*
* @author Rose Browne (s1652834)
*
**/

#ifndef Tree_h
#define Tree_h
#include <fstream>
#include <iostream>

template <class T>
class TreeNode{
	public:
		TreeNode(T info);
		T getValue();
		TreeNode<T> *left;
		TreeNode<T> *right;
	private:
		T value;
};

template <class T>
T TreeNode<T>::getValue(){
	return value;
}

template <class T>
TreeNode<T>::TreeNode(T info){
	value = info;
	left = NULL; 
	right = NULL;
}

template <class T>
class Tree {
	public:
		Tree();
		void insert(T info);
		bool contains(T info);
		void showPreOrder();
		void showInOrder();
		void showPostOrder();
		void saveAsDot(std::string fileName);
		~Tree();
	protected:
		TreeNode<T> *root;
	private:	
		void contains(T info, TreeNode<T> *node, bool &found);
		void destroyTree(TreeNode<T> *node);
		void showPreOrder(TreeNode<T> *node);
		void showInOrder(TreeNode<T> *node);
		void showPostOrder(TreeNode<T> *node);
		void saveAsDot(TreeNode<T> *node, int &parentNode, std::ofstream &file);
		int nodeCounter;
};

template <class T>
Tree<T>::Tree(){
		root = NULL;
}
		
template <class T>
void Tree<T>::insert(T info){
		TreeNode<T> *p = root;
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
		if(root == 0){
			root = new TreeNode<T>(info);
		}
		else if(info < prev->getValue()){
			prev->left = new TreeNode<T>(info);
		}
		else{
			prev->right = new TreeNode<T>(info);
		}
}
	
template <class T>
bool Tree<T>::contains(T info){
		bool found = false;
		if(root != NULL){
			if(root->getValue() == info){
				found = true;
			}
			else{
				contains(info, root->left, found);
				contains(info, root->right, found);
			}
		}
		return found;
}

template <class T>
void Tree<T>::contains(T info, TreeNode<T> *node, bool &found){
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
void Tree<T>:: showPreOrder(){
	if(root != NULL){
		std::cout << root->getValue() << ", ";
		showPreOrder(root->left);
		showPreOrder(root->right);
	}
}

template <class T>
void Tree<T>::showPreOrder(TreeNode<T> *node) {
    if(node != NULL) {
        std::cout << node->getValue() << ", ";
        showPreOrder(node->left);
        showPreOrder(node->right);
    }
}
	
template <class T>
void Tree<T>::showInOrder(){
	if(root != NULL){
		showInOrder(root->left);
		std::cout << root->getValue() << ",  ";
		showInOrder(root->right);
	}
}

template <class T>
void Tree<T>::showInOrder(TreeNode<T> *node){
	if(node != NULL){
		showInOrder(node->left);
		std::cout << node->getValue() << ", ";
		showInOrder(node->right);
	}
}

template <class T>	
void Tree<T>::showPostOrder(){
	if(root != NULL){
		showPostOrder(root->left);
		showPostOrder(root->right);
		std::cout << root->getValue() << ", ";
	}
}

template <class T>
void Tree<T>::showPostOrder(TreeNode<T> *node){
	if(node != NULL){
		showPostOrder(node->left);
		showPostOrder(node->right);
		std::cout << node->getValue() << ", ";
	}
}
	
template <class T>
void Tree<T>::saveAsDot(std::string fileName){
    if(root != NULL) {
        nodeCounter = 1;
        std::ofstream file;
        file.open(fileName.c_str(), std::ios::out);
        file << "digraph BinaryTree {" << std::endl;
        file << "  " << nodeCounter << " [label=\"" << root->getValue() << "\"]" << std::endl;
        int parentNode = 1;
        saveAsDot(root, parentNode, file);
        file << "}" << std::endl;
        file.close();
    } else {
        std::cout << "Er zijn nog geen knopen om uit te printen" << std::endl;
    }
}

template <class T>
void Tree<T>::saveAsDot(TreeNode<T> *leaf, int & parentNode, std::ofstream &file){
    if(leaf != NULL) {
        if(leaf->left != NULL) {
            nodeCounter++;
            file << "  " << nodeCounter << " [label=\"";
            file << leaf->left->getValue() << "\"]" << std::endl;
            file << "  " << parentNode << " -> " << nodeCounter << std::endl;
            int newLeftParentNode = nodeCounter;
            saveAsDot(leaf->left, newLeftParentNode, file);
        }
        if(leaf->right != NULL) {
            nodeCounter++;
            file << "  " << nodeCounter << " [label=\"";
            file << leaf->right->getValue() << "\"]" << std::endl;
            file << "  " << parentNode << " -> " << nodeCounter << std::endl;
            int newRightParentNode = nodeCounter;
            saveAsDot(leaf->right, newRightParentNode, file);
        }
    }
}

template <class T>
void Tree<T>::destroyTree(TreeNode<T> *node){
	if(node != NULL){
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}	
}

template <class T>
Tree<T>::~Tree(){
	destroyTree(root);
}

#endif 
