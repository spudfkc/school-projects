#pragma once
#include <iostream>
#include <string>
#include "SymbolTable.h"

class LinkedList
{
public:
	typedef struct LLnode {
		LLnode *next;
		char data;
		SymbolTable *st;
		LLnode() {
			next = NULL;
			data = 'X';
			st = NULL;
		}
	};

	LinkedList(void);

	~LinkedList(void);

	void insertFront(char);
	void traverse(int);
	void traverse(void);
	void traverse2(void);
	void insertBack(char);
	void insertMid(char, int);
	LLnode* getHead(void);
	void insert(std::string, int); 
	void insert(std::string, char, int);
	void insertSorted(std::string, int);
	void find(std::string, char, int);
	void sortAZ(void);

private:
	LLnode *head, *tail, *curr;

};

