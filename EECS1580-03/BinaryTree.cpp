#include "StdAfx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree(void)
{
	root = new BinaryTree::BTnode;
	root = NULL;
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
void BinaryTree::traverse(BinaryTree::BTnode* start) {
	if(start != NULL)
	{
		traverse(start->left);
		std::cout << start->st->toString() << std::endl;
		traverse(start->right);
	}
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


void BinaryTree::insert(BinaryTree::BTnode* z) {
	BinaryTree::BTnode *y, *x;
	y = NULL;
	x = root;
	while(x != NULL) {
		y = x;
		if(z->st->getID() < x->st->getID())
			x = x->left;
		else x = x->right;
	}
	z->p = y;
	if(y == NULL)
		root = z;
	else if(z->st->getID() < y->st->getID())
		y->left = z;
	else y->right = z;
}

// returns int value of the node's data
int BinaryTree::getData(BinaryTree::BTnode* n) {
	return (n->data - '0');
}

BinaryTree::BTnode* BinaryTree::search(std::string id, BinaryTree::BTnode* leaf) {
	while(leaf != NULL && leaf->st->getID() != id) {
		//std::cout << "searching : " << leaf->st->getID() << std::endl;
		if(id < leaf->st->getID())
			leaf = leaf->left;
		else leaf = leaf->right;
	}
	return leaf;
}


std::string	BinaryTree::getID(BinaryTree::BTnode* n)
{
	return n->st->getID();
}

void BinaryTree::setRoot(BinaryTree::BTnode* r) {
	root = r;
}

void BinaryTree::outputToFile(void) {

	std::ofstream outfile("output.txt");

	writeTreeToFile(root, outfile);

	outfile.close();


}

void BinaryTree::writeTreeToFile(BinaryTree::BTnode* node, std::ostream &os) {

	if(node->left != NULL) writeTreeToFile(node->left, os);
	std::cout << node->st->toString() << std::endl;
	os << node->st->toString() << std::endl;
	if(node->right != NULL) writeTreeToFile(node->right, os);

}