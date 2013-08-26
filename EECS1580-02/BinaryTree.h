#pragma once

#include "LinkedList.h"
#include <iostream>

class BinaryTree
{
private:
	typedef struct BTnode {
		BTnode* left;
		BTnode* right;
		char data;
		BTnode() {
			left  = NULL;
			right = NULL;
		}
	};

	BTnode *root, *curr;
public:
	BinaryTree(LinkedList::LLnode*);
	~BinaryTree(void);

	int opFunction(char);
	BTnode* traverse(BTnode*);
	BTnode* getRoot(void);
	bool isNumber(char);
	void insert(char);
	void insert(char, BTnode*);
	BTnode* search(char);
	BTnode* search(char, BTnode*);

	BTnode* branch(LinkedList::LLnode*);

	int compute(BinaryTree::BTnode*);
};

