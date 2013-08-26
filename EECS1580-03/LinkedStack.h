#pragma once

#include "LinkedList.h"
#include <iostream>

class LinkedStack
{
private:
	LinkedList::LLnode *top;
public:
	LinkedStack(void);
	~LinkedStack(void);
	void push(char);
	char pop(void);
	void traverse();
};

