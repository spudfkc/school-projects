#include "StdAfx.h"
#include "SymbolList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SymbolTable.h"

using namespace std;

// define struct for node
typedef struct node 
{
	SymbolTable cnode;
	node *next;
};

class SymbolList 
{
	node *head;

	// constructro
	SymbolList::SymbolList(string s)
	{
		// initialize LL
		head = NULL;
	}

	SymbolList::~SymbolList(void)
	{
		
	}




	// for declerations
	void SymbolList::insert(string id, int val)
	{

	}

	// find node for ops
	node* SymbolList::traverse(string tofind)
	{
		node *curnt = head;
		while(curnt != NULL)
		{
			if(curnt->cnode.getID().compare(tofind) == 0)
			{
				// match
				return curnt;
			}
			curnt = curnt->next;
		}
	}
}