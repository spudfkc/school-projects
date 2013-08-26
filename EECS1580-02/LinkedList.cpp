#include "StdAfx.h"
#include "LinkedList.h"


// this class hass all the methods for a LinkedList

LinkedList::LinkedList(void)
{
	head = new LLnode;
	tail = new LLnode;
	curr = new LLnode;
}


LinkedList::~LinkedList(void)
{
	// delete all mem allocations
	LLnode* tmp;

	curr = head; 
	while(curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		delete(tmp);
	}
	delete(curr);
	delete(tail);
	delete(head);
}


void LinkedList::insertFront(char c)
{
	LLnode *newnode = new LLnode;				// new node

	std::cout << "inserting at front: " << c << std::endl;

	newnode->data = c;							// set data of newnode
	newnode->next = head;						// set link of newnode
	head = newnode;								// point head to newnode

}

void LinkedList::insertBack(char c) 
{
	LLnode *newnode = new LLnode;				// newnode

	newnode->data = c;							// set data
	newnode->next = NULL;						// set link (should already be NULL tho)

	curr = head;								// goto end of list
	while(curr->next != NULL)
		curr = curr->next;

	curr->next = newnode;						// point end of list to newnode
}

void LinkedList::insertMid(char c, int place)
{
	LLnode *newnode = new LLnode;				// newnode

	newnode->data = c;							// set data

	curr = head;								// goto specified place
	for(int i = 0; i < place ; i++)
		curr = curr->next;
	
	newnode->next = curr->next;					// point newnode to next
	curr->next = newnode;						// point current to newnode
}

void LinkedList::traverse(int start)
{
	curr = head;								// have to start at begining

	for(int i=0; i<start; i++)					// goto where we should 
		curr = curr->next;

	// traverse list and cout every data
	while(curr->next != NULL) 
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}

}

void LinkedList::traverse(void)
{
	curr = head;
	while(curr->next != NULL) 
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}

LinkedList::LLnode* LinkedList::getHead(void) 
{
	return head;
}