/**
*
* @author Rose Browne (s1652834)
*
**/

#ifndef TreeNode_h
#define TreeNode_h
#include <fstream>

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

#endif
