#pragma once
#include "SymbolTable.h"
#include <string>

class LinkedList
{
private: 
   	// define node for LinkedList
	typedef struct node 
	{ 
		public:
			SymbolTable *data;       // data in node 
			node *next;			    // link to next node 
			node() 
			{
				next = NULL;
				data = new SymbolTable();
			}
	}; 

	node *head,*tail,*curr;

public:
	LinkedList(void);
	~LinkedList(void);
    void insert(std::string, int); 
	void display(); 
	void traverse();
	void sort();
	void find(std::string, char, int);
};

