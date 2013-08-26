#include "StdAfx.h"
#include "BinaryTree.h"

// constructor
BinaryTree::BinaryTree(LinkedList::LLnode *start)
{
	root = branch(start);
	curr = new BinaryTree::BTnode;
}

// de-constructor
BinaryTree::~BinaryTree(void)
{
	// TODO : delete ALL nodes in tree

	delete root;
	delete curr;
}

// does operation
int BinaryTree::opFunction(char op) {
	switch(op) {
		case '+' : { break; }
		case '-' : { break; }
		case '*' : { break; }
		case '/' : { break; }
	};
	return 0;
}

// traverses tree, prints out contents
BinaryTree::BTnode* BinaryTree::traverse(BinaryTree::BTnode* start) {
	while(start->left != NULL) {
			// go to left most node
		start = start->left;
		BinaryTree::traverse(start);
	}
	std::cout << start->data << std::endl;
	while(start->right != NULL) {
			// go to right most node
		start = start->right;
		BinaryTree::traverse(start);
	}
	std::cout << start << std::endl;
			// return the node
	return start;
}

// returns root node of tree
BinaryTree::BTnode* BinaryTree::getRoot(void) {
	return root;
}

// returns true if char is a number, false otherwise
bool BinaryTree::isNumber(char test) {
	if((test - '0') <= 9 && (test - '0') >= 0)
		return true;
	else return false;
}

// TODO : don't need this
void BinaryTree::insert(char d) {
	if(root != NULL)
		insert(d, root);
	else {
		root = new BinaryTree::BTnode;
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
}

// TODO : don't need this
void BinaryTree::insert(char d, BinaryTree::BTnode* leaf) {
	if(d < leaf->data)
	{
		if(leaf->left != NULL)
			insert(d, leaf->left);
		else
		{
			leaf->left = new BTnode;
			leaf->left->data = d;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if(d >= leaf->data)
	{
		if(leaf->right != NULL)
			insert(d, leaf->right);
		else
		{
			leaf->right = new BTnode;
			leaf->right->data = d;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

BinaryTree::BTnode* BinaryTree::search(char d) {
	return BinaryTree::search(d, root);
}

BinaryTree::BTnode* BinaryTree::search(char d, BinaryTree::BTnode* leaf) {
	if(leaf != NULL) {
		if(d == leaf->data)
			return leaf;
		if(d < leaf->data)
			return search(d, leaf->left);
		else
			return search(d, leaf->right);
		//return NULL;
	}
}

// creates the tree from a linkedList
BinaryTree::BTnode* BinaryTree::branch(LinkedList::LLnode* start) {

	BinaryTree::BTnode* curr = new BinaryTree::BTnode;		// create new leaf
	curr->data = start->data;								// set leaf data
	curr->left = NULL;
	curr->right = NULL;
	
	//std::cout << "CURR: " << curr->data << std::endl;
	start = start->next;									// look at next node


	// traverse through LinkedList of data
	while(start != NULL) {
		if(BinaryTree::isNumber(start->data)) {				// if next node contains a number
			if(curr->right == NULL) {						// if right leaf is NULL, put new leaf there
				curr->right = new BTnode;					// set new leaf's data
				curr->right->data = start->data;		
				//std::cout << "CURR.R: " << curr->right->data << std::endl;
			} else if(curr->left == NULL) {					// else if left leaf is NULL, put it there
				curr->left = new BTnode;					// set new leaf's data
				curr->left->data = start->data;
				//std::cout << "CURR.L: " << curr->left->data << std::endl;
			} else { // LEAFS ARE FULL 
				// what do here?
				//std::cout << "LEAFS FULL" << std::endl;
				return curr;
			}
			// increment node
			start = start->next;
		}
		else {												// else next node contains an operator
			if(curr->left == NULL) {					
				//std::cout << "BRACNHING LEFT: " << start->data << std::endl;
				curr->left = branch(start);					// if left leaf is null, branch there
				//std::cout << "CURR.L: " << curr->left->data << std::endl;

				// only return if both branches are filled
				if(curr->left == NULL && curr->right ==NULL)
					return curr;
				else 
					start = start->next->next->next;		// continue where next branch should be
				
			}
			else if(curr->right == NULL) {
				//std::cout << "BRACNHING RIGHT: " << start->data << std::endl;
				curr->right = branch(start);				// else if right leaf is null, branch there
				//std::cout << "CURR.R: " << curr->right->data << std::endl;

				// only return if both branches are filled
				if(curr->left == NULL && curr->right ==NULL)
					return curr;
				else 
					start = start->next->next->next;		// continue where next branch should be
				
			}
			else {
				// LEAFS FULL
				//std::cout << "LEAFS FULL" << std::endl;

				return curr;
			}

		}
	}

}

// will compute the final value of the binary tree
int BinaryTree::compute(BinaryTree::BTnode* start) {
	int Lresult, Rresult;
	char b = start->data;

	if(isNumber(b))
		return (b - '0');			// if it's just a number return its value
	else {							// else do the correct operation on the rest of the tree
		switch(b) {
		case '+' : Lresult = compute(start->left) + compute(start->right); break;
		case '-' : Lresult = compute(start->left) - compute(start->right); break;
		case '*' : Lresult = compute(start->left) * compute(start->right); break;
		case '/' : Lresult = compute(start->left) / compute(start->right); break;
		};
		return Lresult;
	}
}