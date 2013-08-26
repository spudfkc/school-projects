#include "StdAfx.h"
#include "LinkedStack.h"


LinkedStack::LinkedStack(void)
{
	top = new LinkedList::LLnode;			// allocate mem
}


LinkedStack::~LinkedStack(void)
{
	if(top == NULL)
		return;
	LinkedList::LLnode* tmp;
	while(top != NULL)
	{
		tmp = top;
		top = top->next;
		delete tmp;
	}
}

void LinkedStack::push(char c)
{
	LinkedList::LLnode* tmp;
	tmp = new LinkedList::LLnode;

	if(tmp == NULL)
		std::cout << "STACK FULL" << std::endl;

	tmp->data = c;
	tmp->next = top;
	top = tmp;
}

char LinkedStack::pop(void) 
{
	if(top == NULL)
		std::cout << "STACK EMPTY" << std::endl;

	//LinkedList::LLnode* tmp;
	char n;
	
	//tmp = top;
	n = top->data;
	top = top->next;

	std::cout << "popped: " << n << std::endl;

	return n;
}

void LinkedStack::traverse()
{
	LinkedList::LLnode* tmp = new LinkedList::LLnode;
	
	tmp = top;
	while(tmp->next != NULL)
	{
		std::cout << tmp->data << std::endl;
		tmp = tmp->next;
	}
}