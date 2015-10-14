//
//  main.cpp
//  Tree
//
//
//

#include <iostream>
#include "TreeNode.h"
#include "Tree.h"
#include "BinarySearchTree.h"

using namespace std;

int main(){

	Tree<int> myTree;
	int getal1 = 13, getal2 = 10, getal3 = 2, getal4 = 12;
	int getal5 = 25, getal6 = 20, getal7 = 31, getal8 = 29;
	myTree.insert(getal1);
	myTree.insert(getal2);
	myTree.insert(getal3);
	myTree.insert(getal4);
	myTree.insert(getal5);
	myTree.insert(getal6);
	myTree.insert(getal7);
	myTree.insert(getal8);
	
	if(myTree.contains(102)){
		cout << "myTree bevat het getal 29." << endl;
	}
	
	cout << "De pre order is: " << endl;
	myTree.showPreOrder();
	cout << endl;
	cout << "De In order is: " << endl;
	myTree.showInOrder();
	cout << endl;
	cout << "De Post order is: " << endl;
	myTree.showPostOrder();
	cout << endl;
	myTree.saveAsDot("dotGraph.txt");
	
	BinarySearchTree<int> mySearchTree;
	
	int getal9 = 28;
	int getal10 = 27;
	
	mySearchTree.insert(getal1);
	mySearchTree.insert(getal2);
	mySearchTree.insert(getal3);
	mySearchTree.insert(getal4);
	mySearchTree.insert(getal5);
	mySearchTree.insert(getal6);
	mySearchTree.insert(getal7);
	mySearchTree.insert(getal8);
	mySearchTree.insert(getal9);
	mySearchTree.insert(getal10);
	
	if(mySearchTree.contains(29)){
		cout << "mySeachTree bevat het getal 29." << endl;
	}
	
	mySearchTree.saveAsDot("dotGraph2.txt");

	mySearchTree.rotateLeft(mySearchTree.getRoot());
	
	mySearchTree.saveAsDot("dotGraph3.txt");
	
  return 0;
}
