#pragma once

#include "LinkedList.h"
#include "SymbolTable.h"
#include <iostream>
#include <string>
#include <fstream>

class BinaryTree
{

public:
	typedef struct BTnode {
		BTnode* left;
		BTnode* right;
		BTnode* p;
		char data;					// still using char because everything already is known to work as chars
									// and I don't want to remake everything if I change it to int. 
									// there is a getData function that will return int value of node's data
		std::string id;
		SymbolTable* st;
		BTnode() {
			left  = NULL;
			right = NULL;
		}
	};

	//BinaryTree(LinkedList::LLnode*);
	BinaryTree(void);
	~BinaryTree(void);

	int opFunction(char);
	int getData(BTnode*);
	std::string getID(BTnode*);
	void traverse(BTnode*);
	BTnode* getRoot(void);
	void setRoot(BTnode*);
	bool isNumber(char);
	void insert(BTnode*);
	BTnode* search(char);
	BTnode* search(std::string, BTnode*);

	BTnode* branch(LinkedList::LLnode*);

	int compute(BinaryTree::BTnode*);

	std::string toString(BTnode*);

	void writeTreeToFile(BTnode*, std::ostream&);
	void outputToFile(void);

private:
	BTnode *root, *curr;
};

